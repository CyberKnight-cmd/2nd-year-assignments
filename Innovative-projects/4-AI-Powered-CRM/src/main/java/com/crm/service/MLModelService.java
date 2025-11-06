package com.crm.service;

import com.crm.entity.Customer;
import com.crm.entity.Communication;
import com.crm.entity.PredictiveAnalytics;
import com.crm.repository.PredictiveAnalyticsRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;
import java.util.List;

@Service
public class MLModelService {
    
    @Autowired
    private PredictiveAnalyticsRepository predictiveAnalyticsRepository;
    
    public double predictCustomerLifetimeValue(Customer customer, List<Communication> communications) {
        // Simple CLV model based on engagement and lead score
        int leadScore = customer.getLeadScore() != null ? customer.getLeadScore() : 0;
        int communicationCount = communications.size();
        
        double baseValue = leadScore * 50; // Base value from lead score
        double engagementMultiplier = Math.min(1 + (communicationCount * 0.1), 3.0); // Max 3x multiplier
        
        // Status multiplier
        double statusMultiplier = switch (customer.getStatus()) {
            case "CUSTOMER" -> 2.0;
            case "PROSPECT" -> 1.5;
            case "LEAD" -> 1.0;
            default -> 0.5;
        };
        
        double clv = baseValue * engagementMultiplier * statusMultiplier;
        
        // Save prediction
        savePrediction(customer, "LIFETIME_VALUE", clv, 0.8, "1_YEAR");
        
        return clv;
    }
    
    public double predictChurnProbability(Customer customer, List<Communication> communications) {
        double churnScore = 0.0;
        
        // Days since last contact
        long daysSinceLastContact = customer.getLastContact() != null ? 
            ChronoUnit.DAYS.between(customer.getLastContact(), LocalDateTime.now()) : 999;
        
        if (daysSinceLastContact > 90) churnScore += 0.4;
        else if (daysSinceLastContact > 60) churnScore += 0.3;
        else if (daysSinceLastContact > 30) churnScore += 0.2;
        
        // Communication frequency
        if (communications.size() < 2) churnScore += 0.3;
        else if (communications.size() < 5) churnScore += 0.1;
        
        // Lead score factor
        int leadScore = customer.getLeadScore() != null ? customer.getLeadScore() : 0;
        if (leadScore < 30) churnScore += 0.3;
        else if (leadScore < 50) churnScore += 0.1;
        
        churnScore = Math.min(churnScore, 1.0);
        
        // Save prediction
        savePrediction(customer, "CHURN_RISK", churnScore, 0.75, "90_DAYS");
        
        return churnScore;
    }
    
    public String predictOptimalContactTime(Customer customer, List<Communication> communications) {
        // Simple heuristic based on customer type and past interactions
        boolean hasCompany = customer.getCompany() != null && !customer.getCompany().isEmpty();
        int leadScore = customer.getLeadScore() != null ? customer.getLeadScore() : 0;
        
        if (hasCompany) {
            // B2B customers
            if (leadScore > 80) return "9:00 AM - 11:00 AM (High priority)";
            else if (leadScore > 60) return "2:00 PM - 4:00 PM (Business hours)";
            else return "10:00 AM - 12:00 PM (Standard)";
        } else {
            // B2C customers
            if (leadScore > 80) return "6:00 PM - 8:00 PM (Evening)";
            else return "Weekend mornings (10:00 AM - 12:00 PM)";
        }
    }
    
    public String generateProductRecommendation(Customer customer, List<Communication> communications) {
        int leadScore = customer.getLeadScore() != null ? customer.getLeadScore() : 0;
        String status = customer.getStatus();
        
        if ("CUSTOMER".equals(status)) {
            if (leadScore > 80) return "Premium upgrade package - High engagement customer";
            else return "Additional services - Maintain relationship";
        } else if ("PROSPECT".equals(status)) {
            if (leadScore > 70) return "Standard package - Ready to convert";
            else return "Trial offer - Build interest";
        } else {
            return "Basic information package - Nurture lead";
        }
    }
    
    public double calculateEngagementScore(Customer customer, List<Communication> communications) {
        if (communications.isEmpty()) return 0.0;
        
        long totalDays = ChronoUnit.DAYS.between(customer.getCreatedAt(), LocalDateTime.now());
        if (totalDays == 0) return 10.0;
        
        double communicationRate = (double) communications.size() / totalDays;
        double engagementScore = Math.min(communicationRate * 100, 10.0);
        
        // Recent activity boost
        long recentComms = communications.stream()
                .filter(c -> c.getTimestamp().isAfter(LocalDateTime.now().minusDays(30)))
                .count();
        
        if (recentComms > 0) engagementScore *= 1.2;
        
        return Math.min(engagementScore, 10.0);
    }
    
    private void savePrediction(Customer customer, String metricType, double value, double confidence, String timeframe) {
        PredictiveAnalytics prediction = new PredictiveAnalytics();
        prediction.setCustomer(customer);
        prediction.setMetricType(metricType);
        prediction.setPredictedValue(value);
        prediction.setConfidence(confidence);
        prediction.setTimeframe(timeframe);
        prediction.setValidUntil(LocalDateTime.now().plusDays(
            timeframe.equals("1_YEAR") ? 365 : timeframe.equals("90_DAYS") ? 90 : 30
        ));
        predictiveAnalyticsRepository.save(prediction);
    }
}