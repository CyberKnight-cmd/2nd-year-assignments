package com.crm.service;

import com.crm.entity.Customer;
import com.crm.entity.Communication;
import com.crm.entity.CustomerInsight;
import com.crm.repository.CustomerInsightRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

@Service
public class CustomerInsightService {
    
    @Autowired
    private CustomerInsightRepository customerInsightRepository;
    
    @Autowired
    private OpenAIService openAIService;
    
    public CustomerInsight analyzeBehaviorPatterns(Customer customer, List<Communication> communications) {
        String behaviorAnalysis = generateBehaviorInsight(customer, communications);
        
        CustomerInsight insight = new CustomerInsight();
        insight.setCustomer(customer);
        insight.setInsightType("BEHAVIOR");
        insight.setInsight(behaviorAnalysis);
        insight.setEngagementLevel(calculateEngagementLevel(communications));
        
        return customerInsightRepository.save(insight);
    }
    
    public String generateSalesForecast(List<Customer> customers) {
        long totalCustomers = customers.size();
        long activeCustomers = customers.stream()
                .filter(c -> c.getLastContact() != null && 
                           c.getLastContact().isAfter(LocalDateTime.now().minusDays(30)))
                .count();
        
        double conversionRate = activeCustomers / (double) totalCustomers;
        int projectedSales = (int) (activeCustomers * conversionRate * 1.2);
        
        return String.format("Projected sales for next 30 days: %d deals based on %d active customers (%.1f%% conversion rate)", 
                           projectedSales, activeCustomers, conversionRate * 100);
    }
    
    public String generatePipelineOptimization(List<Customer> customers) {
        Map<String, Long> statusCounts = customers.stream()
                .collect(Collectors.groupingBy(Customer::getStatus, Collectors.counting()));
        
        long leads = statusCounts.getOrDefault("LEAD", 0L);
        long prospects = statusCounts.getOrDefault("PROSPECT", 0L);
        long customerCount = statusCounts.getOrDefault("CUSTOMER", 0L);
        
        if (leads > prospects * 3) {
            return "Pipeline bottleneck detected: Too many leads not converting to prospects. Focus on lead qualification.";
        } else if (prospects > customerCount * 2) {
            return "Pipeline bottleneck detected: Prospects not converting to customers. Review closing strategies.";
        }
        
        return "Pipeline appears balanced. Continue current strategies and monitor conversion rates.";
    }
    
    public CustomerInsight generatePerformanceInsight(Customer customer, List<Communication> communications) {
        String prompt = String.format(
            "Analyze customer performance: %s, %d communications, lead score %d, status %s. Provide brief insight.",
            customer.getFullName(), communications.size(), customer.getLeadScore(), customer.getStatus()
        );
        
        String aiInsight = openAIService.generateResponse(prompt);
        
        CustomerInsight insight = new CustomerInsight();
        insight.setCustomer(customer);
        insight.setInsightType("PERFORMANCE");
        insight.setInsight(aiInsight);
        insight.setEngagementLevel(calculateEngagementLevel(communications));
        
        return customerInsightRepository.save(insight);
    }
    
    public List<CustomerInsight> getCustomerInsights(Long customerId) {
        return customerInsightRepository.findByCustomerIdOrderByGeneratedAtDesc(customerId);
    }
    
    private String generateBehaviorInsight(Customer customer, List<Communication> communications) {
        if (communications.isEmpty()) {
            return "No communication history available. Consider initial outreach.";
        }
        
        long daysSinceFirstContact = ChronoUnit.DAYS.between(customer.getCreatedAt(), LocalDateTime.now());
        double communicationFrequency = communications.size() / Math.max(daysSinceFirstContact, 1.0);
        
        if (communicationFrequency > 0.5) {
            return "High engagement customer with frequent communication. Strong conversion potential.";
        } else if (communicationFrequency > 0.1) {
            return "Moderate engagement customer. Regular follow-up recommended.";
        } else {
            return "Low engagement customer. May need re-engagement strategy or lead qualification review.";
        }
    }
    
    private int calculateEngagementLevel(List<Communication> communications) {
        if (communications.isEmpty()) return 1;
        
        long recentComms = communications.stream()
                .filter(c -> c.getTimestamp().isAfter(LocalDateTime.now().minusDays(30)))
                .count();
        
        return (int) Math.min(recentComms + 1, 10);
    }
}