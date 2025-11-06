package com.crm.service;

import com.crm.entity.Communication;
import com.crm.entity.Customer;
import com.crm.entity.CustomerInsight;
import com.crm.repository.CustomerInsightRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.time.LocalDateTime;
import java.util.List;

@Service
public class SentimentAnalysisService {
    
    @Autowired
    private OpenAIService openAIService;
    
    @Autowired
    private CustomerInsightRepository customerInsightRepository;
    
    public double analyzeCommunicationSentiment(Communication communication) {
        String content = communication.getContent();
        if (content == null || content.trim().isEmpty()) return 0.0;
        
        return openAIService.analyzeSentiment(content);
    }
    
    public double getAverageSentiment(List<Communication> communications) {
        if (communications.isEmpty()) return 0.0;
        
        return communications.stream()
                .mapToDouble(this::analyzeCommunicationSentiment)
                .average()
                .orElse(0.0);
    }
    
    public void trackCustomerMood(Customer customer, List<Communication> communications) {
        double avgSentiment = getAverageSentiment(communications);
        
        CustomerInsight insight = new CustomerInsight();
        insight.setCustomer(customer);
        insight.setInsightType("BEHAVIOR");
        insight.setSentimentScore(avgSentiment);
        insight.setEngagementLevel(calculateEngagementLevel(communications));
        
        if (avgSentiment < -0.3) {
            insight.setRiskLevel("HIGH");
            insight.setInsight("Customer showing negative sentiment trend. Immediate attention required.");
        } else if (avgSentiment < 0.1) {
            insight.setRiskLevel("MEDIUM");
            insight.setInsight("Customer sentiment is neutral to slightly negative. Monitor closely.");
        } else {
            insight.setRiskLevel("LOW");
            insight.setInsight("Customer sentiment is positive. Good engagement opportunity.");
        }
        
        customerInsightRepository.save(insight);
    }
    
    public List<CustomerInsight> getHighRiskCustomers() {
        return customerInsightRepository.findHighRiskInsights();
    }
    
    public String generateSentimentBasedRecommendation(Customer customer, double sentimentScore) {
        if (sentimentScore < -0.3) {
            return "Schedule immediate call to address concerns and rebuild relationship";
        } else if (sentimentScore < 0.1) {
            return "Send personalized follow-up to gauge satisfaction and identify issues";
        } else {
            return "Leverage positive sentiment for upselling or referral opportunities";
        }
    }
    
    private int calculateEngagementLevel(List<Communication> communications) {
        if (communications.isEmpty()) return 1;
        
        int recentComms = (int) communications.stream()
                .filter(c -> c.getTimestamp().isAfter(LocalDateTime.now().minusDays(30)))
                .count();
        
        return Math.min(recentComms + 1, 10);
    }
}