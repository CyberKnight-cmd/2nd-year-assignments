package com.crm.service;

import com.crm.entity.Customer;
import com.crm.repository.CustomerRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.time.LocalDateTime;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

@Service
public class CustomerService {
    
    @Autowired
    private CustomerRepository customerRepository;
    
    @Autowired
    private AILeadScoringService aiLeadScoringService;
    
    @Autowired
    private CustomerInsightService customerInsightService;
    
    public List<Customer> getAllCustomers() {
        return customerRepository.findAll();
    }
    
    public Optional<Customer> getCustomerById(Long id) {
        return customerRepository.findById(id);
    }
    
    public Customer saveCustomer(Customer customer) {
        return customerRepository.save(customer);
    }
    
    public void deleteCustomer(Long id) {
        customerRepository.deleteById(id);
    }
    
    public List<Customer> getCustomersByStatus(String status) {
        return customerRepository.findByStatus(status);
    }
    
    public List<Customer> searchCustomers(String query) {
        return customerRepository.findByFirstNameContainingIgnoreCaseOrLastNameContainingIgnoreCase(query, query);
    }
    
    public List<Customer> getTopLeads() {
        return customerRepository.findTopLeads();
    }
    
    public void updateLastContact(Long customerId) {
        Optional<Customer> customer = customerRepository.findById(customerId);
        if (customer.isPresent()) {
            Customer c = customer.get();
            c.setLastContact(LocalDateTime.now());
            customerRepository.save(c);
        }
    }
    
    public void updateLeadScore(Long customerId, Integer score) {
        Optional<Customer> customer = customerRepository.findById(customerId);
        if (customer.isPresent()) {
            Customer c = customer.get();
            c.setLeadScore(score);
            customerRepository.save(c);
        }
    }
    
    public Long getCustomerCountByStatus(String status) {
        return customerRepository.countByStatus(status);
    }
    
    // AI-Enhanced Methods
    public void updateAILeadScore(Long customerId) {
        Optional<Customer> customerOpt = customerRepository.findById(customerId);
        if (customerOpt.isPresent()) {
            Customer customer = customerOpt.get();
            int aiScore = aiLeadScoringService.calculateSmartLeadScore(customer, customer.getCommunications());
            customer.setLeadScore(aiScore);
            customerRepository.save(customer);
        }
    }
    
    public void generateCustomerInsights(Long customerId) {
        Optional<Customer> customerOpt = customerRepository.findById(customerId);
        if (customerOpt.isPresent()) {
            Customer customer = customerOpt.get();
            customerInsightService.analyzeBehaviorPatterns(customer, customer.getCommunications());
        }
    }
    
    public double getConversionProbability(Long customerId) {
        Optional<Customer> customerOpt = customerRepository.findById(customerId);
        if (customerOpt.isPresent()) {
            Customer customer = customerOpt.get();
            return aiLeadScoringService.calculateConversionProbability(customer, customer.getCommunications());
        }
        return 0.0;
    }
    
    public List<Customer> getHotProspects() {
        List<Customer> allCustomers = customerRepository.findAll();
        List<Customer> hotProspects = new java.util.ArrayList<>();
        
        for (Customer customer : allCustomers) {
            Integer leadScore = customer.getLeadScore();
            if (leadScore != null && leadScore > 80) {
                hotProspects.add(customer);
            }
        }
        
        return hotProspects;
    }
    
    public List<Customer> getHighRiskCustomers() {
        List<Customer> allCustomers = customerRepository.findAll();
        List<Customer> highRiskCustomers = new java.util.ArrayList<>();
        
        for (Customer customer : allCustomers) {
            Integer leadScore = customer.getLeadScore();
            if (leadScore != null && leadScore < 30 || "INACTIVE".equals(customer.getStatus())) {
                highRiskCustomers.add(customer);
            }
        }
        
        return highRiskCustomers;
    }
}