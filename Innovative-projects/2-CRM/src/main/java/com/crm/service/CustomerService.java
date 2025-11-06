package com.crm.service;

import com.crm.entity.Customer;
import com.crm.repository.CustomerRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.time.LocalDateTime;
import java.util.List;
import java.util.Optional;

@Service
public class CustomerService {
    
    @Autowired
    private CustomerRepository customerRepository;
    
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
}