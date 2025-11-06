package com.crm.entity;

import javax.persistence.*;
import java.time.LocalDateTime;

@Entity
@Table(name = "communications")
public class Communication {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    
    @ManyToOne
    @JoinColumn(name = "customer_id")
    private Customer customer;
    
    private String type; // EMAIL, CALL, MEETING
    private String subject;
    
    @Column(columnDefinition = "TEXT")
    private String content;
    
    private LocalDateTime timestamp;
    private String direction; // INBOUND, OUTBOUND
    
    public Communication() {
        this.timestamp = LocalDateTime.now();
    }
    
    // Getters and Setters
    public Long getId() { return id; }
    public void setId(Long id) { this.id = id; }
    
    public Customer getCustomer() { return customer; }
    public void setCustomer(Customer customer) { this.customer = customer; }
    
    public String getType() { return type; }
    public void setType(String type) { this.type = type; }
    
    public String getSubject() { return subject; }
    public void setSubject(String subject) { this.subject = subject; }
    
    public String getContent() { return content; }
    public void setContent(String content) { this.content = content; }
    
    public LocalDateTime getTimestamp() { return timestamp; }
    public void setTimestamp(LocalDateTime timestamp) { this.timestamp = timestamp; }
    
    public String getDirection() { return direction; }
    public void setDirection(String direction) { this.direction = direction; }
}