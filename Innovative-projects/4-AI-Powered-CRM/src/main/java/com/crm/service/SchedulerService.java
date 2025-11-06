package com.crm.service;

import com.crm.entity.Customer;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Service;
import java.util.List;

@Service
public class SchedulerService {
    
    @Autowired
    private CustomerService customerService;
    
    @Autowired
    private AutomationService automationService;
    
    @Autowired
    private CommunicationService communicationService;
    
    @Autowired
    private SentimentAnalysisService sentimentAnalysisService;
    
    // Run every hour to check for automated tasks
    @Scheduled(fixedRate = 3600000) // 1 hour
    public void processAutomatedTasks() {
        List<Customer> customers = customerService.getAllCustomers();
        
        for (Customer customer : customers) {
            var communications = communicationService.getCommunicationsByCustomer(customer.getId());
            
            // Create smart tasks for customers needing attention
            if (shouldCreateTask(customer, communications)) {
                automationService.createSmartTask(customer, communications);
            }
            
            // Schedule follow-ups
            if (shouldScheduleFollowUp(customer, communications)) {
                automationService.scheduleAutomatedFollowUp(customer, communications);
            }
        }
    }
    
    // Run every 4 hours to process alerts
    @Scheduled(fixedRate = 14400000) // 4 hours
    public void processIntelligentAlerts() {
        List<Customer> customers = customerService.getAllCustomers();
        
        // Process churn risk alerts
        automationService.processChurnRiskAlerts(customers);
        
        // Process high-value opportunities
        automationService.processHighValueOpportunities(customers);
        
        // Check for negative sentiment trends
        var highRiskCustomers = sentimentAnalysisService.getHighRiskCustomers();
        for (var insight : highRiskCustomers) {
            if ("HIGH".equals(insight.getRiskLevel())) {
                automationService.createIntelligentAlert(
                    insight.getCustomer(), 
                    "SENTIMENT_ALERT", 
                    "Negative sentiment detected: " + insight.getInsight()
                );
            }
        }
    }
    
    // Run daily to update AI scores
    @Scheduled(cron = "0 0 2 * * *") // 2 AM daily
    public void updateAIScores() {
        List<Customer> customers = customerService.getAllCustomers();
        
        for (Customer customer : customers) {
            customerService.updateAILeadScore(customer.getId());
            customerService.generateCustomerInsights(customer.getId());
        }
    }
    
    private boolean shouldCreateTask(Customer customer, List communications) {
        // Check if customer needs attention based on last contact
        return customer.getLastContact() == null || 
               customer.getLastContact().isBefore(java.time.LocalDateTime.now().minusDays(7));
    }
    
    private boolean shouldScheduleFollowUp(Customer customer, List communications) {
        // Check if customer is a high-value lead without recent follow-up
        int leadScore = customer.getLeadScore() != null ? customer.getLeadScore() : 0;
        return leadScore > 70 && "LEAD".equals(customer.getStatus());
    }
}