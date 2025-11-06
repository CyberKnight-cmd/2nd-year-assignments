package com.crm.service;

import com.crm.entity.Customer;
import com.crm.entity.Communication;
import com.crm.entity.AIRecommendation;
import com.crm.entity.PredictiveAnalytics;
import com.crm.repository.AIRecommendationRepository;
import com.crm.repository.PredictiveAnalyticsRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;
import java.util.List;

@Service
public class RecommendationService {
    
    @Autowired
    private AIRecommendationEngine aiRecommendationEngine;
    
    @Autowired
    private AIRecommendationRepository aiRecommendationRepository;
    
    @Autowired
    private PredictiveAnalyticsRepository predictiveAnalyticsRepository;
    
    public AIRecommendation generateNextBestAction(Customer customer, List<Communication> communications) {
        String action = aiRecommendationEngine.generateNextBestAction(customer, communications);
        
        AIRecommendation recommendation = new AIRecommendation();
        recommendation.setCustomer(customer);
        recommendation.setType("NEXT_ACTION");
        recommendation.setRecommendation(action);
        recommendation.setConfidence(0.8);
        
        return aiRecommendationRepository.save(recommendation);
    }
    
    public String recommendCommunicationChannel(Customer customer, List<Communication> communications) {
        if (communications.isEmpty()) return "EMAIL";
        
        String lastChannel = communications.get(0).getType();
        long daysSinceLastContact = customer.getLastContact() != null ? 
            ChronoUnit.DAYS.between(customer.getLastContact(), LocalDateTime.now()) : 999;
        
        if (daysSinceLastContact > 14) return "PHONE";
        if (lastChannel.equals("EMAIL")) return "PHONE";
        return "EMAIL";
    }
    
    public String generatePersonalizedTemplate(Customer customer, String messageType) {
        return aiRecommendationEngine.generatePersonalizedMessage(customer, messageType);
    }
    
    public AIRecommendation identifyUpsellOpportunity(Customer customer) {
        if (!"CUSTOMER".equals(customer.getStatus())) return null;
        
        AIRecommendation recommendation = new AIRecommendation();
        recommendation.setCustomer(customer);
        recommendation.setType("UPSELL");
        recommendation.setRecommendation("Customer shows high engagement. Consider premium service offering.");
        recommendation.setConfidence(0.7);
        
        return aiRecommendationRepository.save(recommendation);
    }
    
    public double assessChurnRisk(Customer customer, List<Communication> communications) {
        long daysSinceLastContact = customer.getLastContact() != null ? 
            ChronoUnit.DAYS.between(customer.getLastContact(), LocalDateTime.now()) : 999;
        
        double riskScore = 0.0;
        if (daysSinceLastContact > 90) riskScore += 0.4;
        if (communications.size() < 2) riskScore += 0.3;
        if (customer.getLeadScore() < 30) riskScore += 0.3;
        
        // Save churn risk prediction
        PredictiveAnalytics churnPrediction = new PredictiveAnalytics();
        churnPrediction.setCustomer(customer);
        churnPrediction.setMetricType("CHURN_RISK");
        churnPrediction.setPredictedValue(Math.min(riskScore, 1.0));
        churnPrediction.setConfidence(0.75);
        churnPrediction.setTimeframe("90_DAYS");
        churnPrediction.setValidUntil(LocalDateTime.now().plusDays(90));
        predictiveAnalyticsRepository.save(churnPrediction);
        
        return Math.min(riskScore, 1.0);
    }
    
    public List<AIRecommendation> getPendingRecommendations(Long customerId) {
        return aiRecommendationRepository.findByCustomerIdAndStatus(customerId, "PENDING");
    }
    
    public int calculateOptimalFollowUpDays(Customer customer, List<Communication> communications) {
        if (communications.isEmpty()) return 7;
        
        int leadScore = customer.getLeadScore() != null ? customer.getLeadScore() : 0;
        if (leadScore > 80) return 3;
        if (leadScore > 60) return 5;
        return 7;
    }
}