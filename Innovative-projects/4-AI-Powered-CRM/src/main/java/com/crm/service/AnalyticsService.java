package com.crm.service;

import com.crm.entity.Customer;
import com.crm.repository.CustomerRepository;
import com.crm.repository.InvoiceRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.math.BigDecimal;
import java.util.HashMap;
import java.util.Map;

@Service
public class AnalyticsService {
    
    @Autowired
    private CustomerRepository customerRepository;
    
    @Autowired
    private InvoiceRepository invoiceRepository;
    
    @Autowired
    private PredictiveAnalyticsService predictiveAnalyticsService;
    
    @Autowired
    private CustomerInsightService customerInsightService;
    
    @Autowired
    private CustomerService customerService;
    
    public Map<String, Object> getDashboardAnalytics() {
        Map<String, Object> analytics = new HashMap<>();
        
        // Customer metrics
        analytics.put("totalCustomers", customerRepository.count());
        analytics.put("leadCount", customerRepository.countByStatus("LEAD"));
        analytics.put("prospectCount", customerRepository.countByStatus("PROSPECT"));
        analytics.put("customerCount", customerRepository.countByStatus("CUSTOMER"));
        
        // Revenue metrics
        BigDecimal totalRevenue = invoiceRepository.getTotalRevenue();
        BigDecimal pendingRevenue = invoiceRepository.getPendingRevenue();
        analytics.put("totalRevenue", totalRevenue != null ? totalRevenue : BigDecimal.ZERO);
        analytics.put("pendingRevenue", pendingRevenue != null ? pendingRevenue : BigDecimal.ZERO);
        
        // Conversion rates
        long totalLeads = customerRepository.countByStatus("LEAD");
        long totalCustomers = customerRepository.countByStatus("CUSTOMER");
        double conversionRate = totalLeads > 0 ? (double) totalCustomers / totalLeads * 100 : 0;
        analytics.put("conversionRate", Math.round(conversionRate * 100.0) / 100.0);
        
        return analytics;
    }
    
    public Map<String, Long> getStatusDistribution() {
        Map<String, Long> distribution = new HashMap<>();
        distribution.put("LEAD", customerRepository.countByStatus("LEAD"));
        distribution.put("PROSPECT", customerRepository.countByStatus("PROSPECT"));
        distribution.put("CUSTOMER", customerRepository.countByStatus("CUSTOMER"));
        distribution.put("INACTIVE", customerRepository.countByStatus("INACTIVE"));
        return distribution;
    }
    
    // AI-Enhanced Analytics Methods
    public Map<String, Object> getPredictiveAnalytics() {
        Map<String, Object> analytics = new HashMap<>();
        
        var customers = customerService.getAllCustomers();
        
        // Generate AI predictions for all customers dynamically
        int highRiskCount = 0;
        int highConversionCount = 0;
        
        for (Customer customer : customers) {
            // Generate churn risk prediction
            double churnRisk = calculateChurnRisk(customer);
            if (churnRisk > 0.7) {
                highRiskCount++;
            }
            
            // Generate conversion probability
            double conversionProb = calculateConversionProbability(customer);
            if (conversionProb > 0.8) {
                highConversionCount++;
            }
        }
        
        // Revenue forecasting
        double forecastedRevenue = predictiveAnalyticsService.forecastRevenue(customers);
        analytics.put("forecastedRevenue", Math.round(forecastedRevenue * 100.0) / 100.0);
        
        // Dynamic counts
        analytics.put("highRiskCustomerCount", highRiskCount);
        analytics.put("highConversionCount", highConversionCount);
        
        // Sales forecast
        String salesForecast = customerInsightService.generateSalesForecast(customers);
        analytics.put("salesForecast", salesForecast);
        
        // Pipeline optimization
        String pipelineOptimization = customerInsightService.generatePipelineOptimization(customers);
        analytics.put("pipelineOptimization", pipelineOptimization);
        
        // Generate AI recommendations
        String aiRecommendations = generateAIRecommendations(customers, highRiskCount, highConversionCount);
        analytics.put("aiRecommendations", aiRecommendations);
        
        return analytics;
    }
    
    private double calculateChurnRisk(Customer customer) {
        double risk = 0.0;
        
        // Days since last contact
        if (customer.getLastContact() == null) {
            risk += 0.4;
        } else {
            long daysSince = java.time.temporal.ChronoUnit.DAYS.between(customer.getLastContact(), java.time.LocalDateTime.now());
            if (daysSince > 90) risk += 0.4;
            else if (daysSince > 60) risk += 0.3;
            else if (daysSince > 30) risk += 0.2;
        }
        
        // Lead score factor
        int leadScore = customer.getLeadScore() != null ? customer.getLeadScore() : 0;
        if (leadScore < 30) risk += 0.3;
        else if (leadScore < 50) risk += 0.1;
        
        return Math.min(risk, 1.0);
    }
    
    private double calculateConversionProbability(Customer customer) {
        int leadScore = customer.getLeadScore() != null ? customer.getLeadScore() : 0;
        return leadScore / 100.0;
    }
    
    private String generateAIRecommendations(java.util.List<Customer> customers, int highRiskCount, int highConversionCount) {
        if (highRiskCount > 0 && highConversionCount > 0) {
            return String.format("Focus on %d hot prospects while addressing %d high-risk customers immediately.", highConversionCount, highRiskCount);
        } else if (highRiskCount > 0) {
            return String.format("URGENT: %d customers at high churn risk. Implement retention strategy immediately.", highRiskCount);
        } else if (highConversionCount > 0) {
            return String.format("Excellent! %d hot prospects ready for conversion. Schedule demos and close deals.", highConversionCount);
        } else {
            long totalLeads = customers.stream().filter(c -> "LEAD".equals(c.getStatus())).count();
            if (totalLeads > 10) {
                return "Focus on lead qualification - many leads need nurturing to increase conversion rates.";
            } else {
                return "Pipeline appears balanced. Continue current strategies and monitor conversion rates.";
            }
        }
    }
    
    public String generateAIInsightsReport() {
        var customers = customerService.getAllCustomers();
        return predictiveAnalyticsService.generateForecastReport(customers);
    }
}