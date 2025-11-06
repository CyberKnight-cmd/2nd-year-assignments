package com.crm.entity;

import javax.persistence.*;
import javax.validation.constraints.Email;
import javax.validation.constraints.NotBlank;
import java.time.LocalDateTime;
import java.util.List;

@Entity
@Table(name = "customers")
public class Customer {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    
    @NotBlank
    private String firstName;
    
    @NotBlank
    private String lastName;
    
    @Email
    @Column(unique = true)
    private String email;
    
    private String phone;
    private String company;
    private String status; // LEAD, PROSPECT, CUSTOMER, INACTIVE
    private Integer leadScore;
    private LocalDateTime createdAt;
    private LocalDateTime lastContact;
    
    @OneToMany(mappedBy = "customer", cascade = CascadeType.ALL)
    private List<Communication> communications;
    
    @OneToMany(mappedBy = "customer", cascade = CascadeType.ALL)
    private List<Invoice> invoices;
    
    public Customer() {
        this.createdAt = LocalDateTime.now();
        this.status = "LEAD";
        this.leadScore = 0;
    }
    
    // Getters and Setters
    public Long getId() { return id; }
    public void setId(Long id) { this.id = id; }
    
    public String getFirstName() { return firstName; }
    public void setFirstName(String firstName) { this.firstName = firstName; }
    
    public String getLastName() { return lastName; }
    public void setLastName(String lastName) { this.lastName = lastName; }
    
    public String getEmail() { return email; }
    public void setEmail(String email) { this.email = email; }
    
    public String getPhone() { return phone; }
    public void setPhone(String phone) { this.phone = phone; }
    
    public String getCompany() { return company; }
    public void setCompany(String company) { this.company = company; }
    
    public String getStatus() { return status; }
    public void setStatus(String status) { this.status = status; }
    
    public Integer getLeadScore() { return leadScore; }
    public void setLeadScore(Integer leadScore) { this.leadScore = leadScore; }
    
    public LocalDateTime getCreatedAt() { return createdAt; }
    public void setCreatedAt(LocalDateTime createdAt) { this.createdAt = createdAt; }
    
    public LocalDateTime getLastContact() { return lastContact; }
    public void setLastContact(LocalDateTime lastContact) { this.lastContact = lastContact; }
    
    public List<Communication> getCommunications() { return communications; }
    public void setCommunications(List<Communication> communications) { this.communications = communications; }
    
    public List<Invoice> getInvoices() { return invoices; }
    public void setInvoices(List<Invoice> invoices) { this.invoices = invoices; }
    
    public String getFullName() {
        return firstName + " " + lastName;
    }
}