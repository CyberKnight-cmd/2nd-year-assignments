package com.crm.entity;

import javax.persistence.*;
import java.time.LocalDateTime;

@Entity
@Table(name = "customer_insights")
public class CustomerInsight {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    
    @ManyToOne
    @JoinColumn(name = "customer_id")
    private Customer customer;
    
    private String insightType; // BEHAVIOR, PREFERENCE, RISK, OPPORTUNITY
    private String insight;
    private Double sentimentScore;
    private Integer engagementLevel; // 1-10
    private String riskLevel; // LOW, MEDIUM, HIGH
    private LocalDateTime generatedAt;
    
    public CustomerInsight() {
        this.generatedAt = LocalDateTime.now();
    }
    
    // Getters and Setters
    public Long getId() { return id; }
    public void setId(Long id) { this.id = id; }
    
    public Customer getCustomer() { return customer; }
    public void setCustomer(Customer customer) { this.customer = customer; }
    
    public String getInsightType() { return insightType; }
    public void setInsightType(String insightType) { this.insightType = insightType; }
    
    public String getInsight() { return insight; }
    public void setInsight(String insight) { this.insight = insight; }
    
    public Double getSentimentScore() { return sentimentScore; }
    public void setSentimentScore(Double sentimentScore) { this.sentimentScore = sentimentScore; }
    
    public Integer getEngagementLevel() { return engagementLevel; }
    public void setEngagementLevel(Integer engagementLevel) { this.engagementLevel = engagementLevel; }
    
    public String getRiskLevel() { return riskLevel; }
    public void setRiskLevel(String riskLevel) { this.riskLevel = riskLevel; }
    
    public LocalDateTime getGeneratedAt() { return generatedAt; }
    public void setGeneratedAt(LocalDateTime generatedAt) { this.generatedAt = generatedAt; }
}