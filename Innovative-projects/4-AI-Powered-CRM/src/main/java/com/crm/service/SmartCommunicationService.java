package com.crm.service;

import com.crm.entity.Customer;
import com.crm.entity.Communication;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;
import java.util.List;

@Service
public class SmartCommunicationService {
    
    @Autowired
    private OpenAIService openAIService;
    
    @Autowired
    private AIRecommendationEngine aiRecommendationEngine;
    
    public String generateEmailTemplate(Customer customer, String purpose) {
        String prompt = String.format(
            "Generate a professional %s email for %s at %s. Keep it concise and personalized.",
            purpose, customer.getFullName(), customer.getCompany()
        );
        
        return openAIService.generateResponse(prompt);
    }
    
    public String generateFollowUpEmail(Customer customer, Communication lastCommunication) {
        String prompt = String.format(
            "Generate a follow-up email for %s based on last communication: '%s'. Be professional and engaging.",
            customer.getFullName(), 
            lastCommunication.getContent().substring(0, Math.min(100, lastCommunication.getContent().length()))
        );
        
        return openAIService.generateResponse(prompt);
    }
    
    public int calculateOptimalResponseTime(Customer customer, List<Communication> communications) {
        if (communications.isEmpty()) return 24; // Default 24 hours
        
        int leadScore = customer.getLeadScore() != null ? customer.getLeadScore() : 0;
        
        if (leadScore > 80) return 2;  // 2 hours for hot leads
        if (leadScore > 60) return 6;  // 6 hours for warm leads
        if (leadScore > 40) return 12; // 12 hours for medium leads
        return 24; // 24 hours for cold leads
    }
    
    public String recommendCommunicationFrequency(Customer customer, List<Communication> communications) {
        long daysSinceLastContact = customer.getLastContact() != null ? 
            ChronoUnit.DAYS.between(customer.getLastContact(), LocalDateTime.now()) : 999;
        
        String status = customer.getStatus();
        int leadScore = customer.getLeadScore() != null ? customer.getLeadScore() : 0;
        
        if ("LEAD".equals(status) && leadScore > 70) {
            return "Contact every 3-5 days while interest is high";
        } else if ("PROSPECT".equals(status)) {
            return "Weekly follow-up recommended to maintain engagement";
        } else if ("CUSTOMER".equals(status)) {
            return "Monthly check-ins to ensure satisfaction and identify opportunities";
        } else if (daysSinceLastContact > 30) {
            return "Immediate re-engagement required - customer may be at risk";
        }
        
        return "Follow standard communication schedule based on lead score";
    }
    
    public String generatePersonalizedContent(Customer customer, String contentType) {
        return aiRecommendationEngine.generatePersonalizedMessage(customer, contentType);
    }
    
    public String suggestBestContactTime(Customer customer) {
        // Simple heuristic based on customer type
        if (customer.getCompany() != null && !customer.getCompany().isEmpty()) {
            return "Business hours (9 AM - 5 PM) on weekdays for B2B contacts";
        } else {
            return "Early evening (6 PM - 8 PM) or weekends for B2C contacts";
        }
    }
    
    public String generateMeetingRequest(Customer customer, String meetingPurpose) {
        String prompt = String.format(
            "Generate a professional meeting request email for %s at %s. Purpose: %s. Include 2-3 time slot options.",
            customer.getFullName(), customer.getCompany(), meetingPurpose
        );
        
        return openAIService.generateResponse(prompt);
    }
    
    public boolean shouldSendFollowUp(Customer customer, Communication lastCommunication) {
        if (lastCommunication == null) return true;
        
        long daysSinceLastComm = ChronoUnit.DAYS.between(lastCommunication.getTimestamp(), LocalDateTime.now());
        int leadScore = customer.getLeadScore() != null ? customer.getLeadScore() : 0;
        
        if (leadScore > 80 && daysSinceLastComm > 3) return true;
        if (leadScore > 60 && daysSinceLastComm > 7) return true;
        if (daysSinceLastComm > 14) return true;
        
        return false;
    }
}