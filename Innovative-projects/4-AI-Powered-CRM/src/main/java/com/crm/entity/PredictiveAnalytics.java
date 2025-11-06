package com.crm.entity;

import javax.persistence.*;
import java.time.LocalDateTime;

@Entity
@Table(name = "predictive_analytics")
public class PredictiveAnalytics {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    
    @ManyToOne
    @JoinColumn(name = "customer_id")
    private Customer customer;
    
    private String metricType; // CONVERSION_PROBABILITY, CHURN_RISK, LIFETIME_VALUE
    private Double predictedValue;
    private Double confidence;
    private String timeframe; // 30_DAYS, 90_DAYS, 1_YEAR
    private LocalDateTime predictionDate;
    private LocalDateTime validUntil;
    
    public PredictiveAnalytics() {
        this.predictionDate = LocalDateTime.now();
    }
    
    // Getters and Setters
    public Long getId() { return id; }
    public void setId(Long id) { this.id = id; }
    
    public Customer getCustomer() { return customer; }
    public void setCustomer(Customer customer) { this.customer = customer; }
    
    public String getMetricType() { return metricType; }
    public void setMetricType(String metricType) { this.metricType = metricType; }
    
    public Double getPredictedValue() { return predictedValue; }
    public void setPredictedValue(Double predictedValue) { this.predictedValue = predictedValue; }
    
    public Double getConfidence() { return confidence; }
    public void setConfidence(Double confidence) { this.confidence = confidence; }
    
    public String getTimeframe() { return timeframe; }
    public void setTimeframe(String timeframe) { this.timeframe = timeframe; }
    
    public LocalDateTime getPredictionDate() { return predictionDate; }
    public void setPredictionDate(LocalDateTime predictionDate) { this.predictionDate = predictionDate; }
    
    public LocalDateTime getValidUntil() { return validUntil; }
    public void setValidUntil(LocalDateTime validUntil) { this.validUntil = validUntil; }
}