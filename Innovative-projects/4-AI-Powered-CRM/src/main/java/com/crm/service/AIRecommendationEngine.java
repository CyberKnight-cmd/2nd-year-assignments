package com.crm.service;

import com.crm.entity.Customer;
import com.crm.entity.Communication;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;
import java.util.List;

@Service
public class AIRecommendationEngine {
    
    @Autowired
    private OpenAIService openAIService;
    
    public String generateNextBestAction(Customer customer, List<Communication> communications) {
        long daysSinceLastContact = customer.getLastContact() != null ? 
            ChronoUnit.DAYS.between(customer.getLastContact(), LocalDateTime.now()) : 999;
        
        String prompt = String.format(
            "Customer: %s, Status: %s, Lead Score: %d, Days since last contact: %d. " +
            "Suggest next best action in 1-2 sentences.",
            customer.getFullName(), customer.getStatus(), customer.getLeadScore(), daysSinceLastContact
        );
        
        return openAIService.generateResponse(prompt);
    }
    
    public int calculateAILeadScore(Customer customer, List<Communication> communications) {
        int baseScore = customer.getLeadScore() != null ? customer.getLeadScore() : 0;
        
        // Communication frequency boost
        int commCount = communications.size();
        int frequencyBoost = Math.min(commCount * 5, 30);
        
        // Recency boost
        long daysSinceLastContact = customer.getLastContact() != null ? 
            ChronoUnit.DAYS.between(customer.getLastContact(), LocalDateTime.now()) : 999;
        int recencyBoost = daysSinceLastContact < 7 ? 20 : daysSinceLastContact < 30 ? 10 : 0;
        
        return Math.min(baseScore + frequencyBoost + recencyBoost, 100);
    }
    
    public String generatePersonalizedMessage(Customer customer, String messageType) {
        String prompt = String.format(
            "Write a %s message for customer %s (company: %s, status: %s). Keep it professional and brief.",
            messageType, customer.getFullName(), customer.getCompany(), customer.getStatus()
        );
        
        return openAIService.generateResponse(prompt);
    }
}