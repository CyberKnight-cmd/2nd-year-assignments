package com.crm.service;

import com.crm.entity.Customer;
import com.crm.entity.PredictiveAnalytics;
import com.crm.repository.PredictiveAnalyticsRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.time.LocalDateTime;
import java.util.List;

@Service
public class PredictiveAnalyticsService {
    
    @Autowired
    private PredictiveAnalyticsRepository predictiveAnalyticsRepository;
    
    public PredictiveAnalytics predictCustomerLifetimeValue(Customer customer) {
        double clv = calculateLifetimeValue(customer);
        
        PredictiveAnalytics prediction = new PredictiveAnalytics();
        prediction.setCustomer(customer);
        prediction.setMetricType("LIFETIME_VALUE");
        prediction.setPredictedValue(clv);
        prediction.setConfidence(0.75);
        prediction.setTimeframe("1_YEAR");
        prediction.setValidUntil(LocalDateTime.now().plusDays(365));
        
        return predictiveAnalyticsRepository.save(prediction);
    }
    
    public List<PredictiveAnalytics> getHighChurnRiskCustomers() {
        return predictiveAnalyticsRepository.findHighChurnRiskCustomers();
    }
    
    public List<PredictiveAnalytics> getHighConversionProbabilityCustomers() {
        return predictiveAnalyticsRepository.findHighConversionProbabilityCustomers();
    }
    
    public double forecastRevenue(List<Customer> customers) {
        return customers.stream()
                .filter(c -> "CUSTOMER".equals(c.getStatus()))
                .mapToDouble(this::calculateLifetimeValue)
                .sum() * 0.3; // 30% of CLV as annual revenue forecast
    }
    
    public String generateForecastReport(List<Customer> customers) {
        long totalCustomers = customers.size();
        long activeCustomers = customers.stream()
                .filter(c -> "CUSTOMER".equals(c.getStatus()))
                .count();
        
        double projectedRevenue = forecastRevenue(customers);
        
        return String.format("Forecast: %d total customers, %d active. Projected annual revenue: $%.2f", 
                           totalCustomers, activeCustomers, projectedRevenue);
    }
    
    private double calculateLifetimeValue(Customer customer) {
        int leadScore = customer.getLeadScore() != null ? customer.getLeadScore() : 0;
        double baseValue = leadScore * 100; // Base CLV calculation
        
        if ("CUSTOMER".equals(customer.getStatus())) {
            baseValue *= 1.5; // Existing customers have higher CLV
        }
        
        return baseValue;
    }
}