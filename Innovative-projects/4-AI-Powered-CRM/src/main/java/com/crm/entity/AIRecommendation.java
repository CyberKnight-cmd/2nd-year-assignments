package com.crm.entity;

import javax.persistence.*;
import java.time.LocalDateTime;

@Entity
@Table(name = "ai_recommendations")
public class AIRecommendation {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    
    @ManyToOne
    @JoinColumn(name = "customer_id")
    private Customer customer;
    
    private String type; // NEXT_ACTION, FOLLOW_UP, UPSELL, etc.
    private String recommendation;
    private Double confidence;
    private String status; // PENDING, ACCEPTED, DISMISSED
    private LocalDateTime createdAt;
    private LocalDateTime updatedAt;
    
    public AIRecommendation() {
        this.createdAt = LocalDateTime.now();
        this.status = "PENDING";
    }
    
    // Getters and Setters
    public Long getId() { return id; }
    public void setId(Long id) { this.id = id; }
    
    public Customer getCustomer() { return customer; }
    public void setCustomer(Customer customer) { this.customer = customer; }
    
    public String getType() { return type; }
    public void setType(String type) { this.type = type; }
    
    public String getRecommendation() { return recommendation; }
    public void setRecommendation(String recommendation) { this.recommendation = recommendation; }
    
    public Double getConfidence() { return confidence; }
    public void setConfidence(Double confidence) { this.confidence = confidence; }
    
    public String getStatus() { return status; }
    public void setStatus(String status) { this.status = status; }
    
    public LocalDateTime getCreatedAt() { return createdAt; }
    public void setCreatedAt(LocalDateTime createdAt) { this.createdAt = createdAt; }
    
    public LocalDateTime getUpdatedAt() { return updatedAt; }
    public void setUpdatedAt(LocalDateTime updatedAt) { this.updatedAt = updatedAt; }
}