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
public class AILeadScoringService {
    
    @Autowired
    private SentimentAnalysisService sentimentAnalysisService;
    
    @Autowired
    private PredictiveAnalyticsRepository predictiveAnalyticsRepository;
    
    public int calculateSmartLeadScore(Customer customer, List<Communication> communications) {
        int baseScore = 0;
        
        // Communication frequency (0-30 points)
        int commCount = communications.size();
        int frequencyScore = Math.min(commCount * 3, 30);
        
        // Sentiment analysis (0-25 points)
        double avgSentiment = sentimentAnalysisService.getAverageSentiment(communications);
        int sentimentScore = (int) ((avgSentiment + 1) * 12.5); // Convert -1,1 to 0,25
        
        // Engagement patterns (0-20 points)
        int engagementScore = calculateEngagementScore(customer, communications);
        
        // Company size estimation (0-15 points)
        int companySizeScore = estimateCompanySizeScore(customer.getCompany());
        
        // Recency boost (0-10 points)
        int recencyScore = calculateRecencyScore(customer.getLastContact());
        
        baseScore = frequencyScore + sentimentScore + engagementScore + companySizeScore + recencyScore;
        return Math.min(baseScore, 100);
    }
    
    public double calculateConversionProbability(Customer customer, List<Communication> communications) {
        int leadScore = calculateSmartLeadScore(customer, communications);
        double probability = leadScore / 100.0;
        
        // Save prediction
        PredictiveAnalytics prediction = new PredictiveAnalytics();
        prediction.setCustomer(customer);
        prediction.setMetricType("CONVERSION_PROBABILITY");
        prediction.setPredictedValue(probability);
        prediction.setConfidence(0.85);
        prediction.setTimeframe("30_DAYS");
        prediction.setValidUntil(LocalDateTime.now().plusDays(30));
        predictiveAnalyticsRepository.save(prediction);
        
        return probability;
    }
    
    private int calculateEngagementScore(Customer customer, List<Communication> communications) {
        if (communications.isEmpty()) return 0;
        
        long totalDays = ChronoUnit.DAYS.between(customer.getCreatedAt(), LocalDateTime.now());
        if (totalDays == 0) return 10;
        
        double engagementRate = (double) communications.size() / totalDays;
        return (int) Math.min(engagementRate * 100, 20);
    }
    
    private int estimateCompanySizeScore(String company) {
        if (company == null || company.isEmpty()) return 5;
        
        String[] largeCorp = {"Corp", "Corporation", "Inc", "LLC", "Ltd", "Group", "Holdings"};
        for (String indicator : largeCorp) {
            if (company.contains(indicator)) return 15;
        }
        return 8;
    }
    
    private int calculateRecencyScore(LocalDateTime lastContact) {
        if (lastContact == null) return 0;
        
        long daysSince = ChronoUnit.DAYS.between(lastContact, LocalDateTime.now());
        if (daysSince < 7) return 10;
        if (daysSince < 30) return 5;
        return 0;
    }
}