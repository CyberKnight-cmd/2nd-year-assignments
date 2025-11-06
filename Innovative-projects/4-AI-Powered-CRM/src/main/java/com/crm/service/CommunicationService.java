package com.crm.service;

import com.crm.entity.Communication;
import com.crm.repository.CommunicationRepository;
import com.crm.repository.CustomerRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.time.LocalDateTime;
import java.util.List;

@Service
public class CommunicationService {
    
    @Autowired
    private CommunicationRepository communicationRepository;
    
    @Autowired
    private SentimentAnalysisService sentimentAnalysisService;
    
    @Autowired
    private CustomerRepository customerRepository;
    
    public List<Communication> getAllCommunications() {
        return communicationRepository.findAll();
    }
    
    public List<Communication> getCommunicationsByCustomer(Long customerId) {
        return communicationRepository.findByCustomerIdOrderByTimestampDesc(customerId);
    }
    
    public Communication saveCommunication(Communication communication) {
        Communication saved = communicationRepository.save(communication);
        
        // Update last contact directly
        updateLastContact(communication.getCustomer().getId());
        
        // Analyze sentiment for new communication
        analyzeCommunicationSentiment(saved);
        
        return saved;
    }
    
    public List<Communication> getRecentCommunications() {
        return communicationRepository.findAll().stream()
                .sorted((c1, c2) -> c2.getTimestamp().compareTo(c1.getTimestamp()))
                .limit(10)
                .toList();
    }
    
    // AI-Enhanced Methods
    public double analyzeCommunicationSentiment(Communication communication) {
        return sentimentAnalysisService.analyzeCommunicationSentiment(communication);
    }
    
    public void trackCustomerSentiment(Long customerId) {
        List<Communication> communications = getCommunicationsByCustomer(customerId);
        if (!communications.isEmpty()) {
            sentimentAnalysisService.trackCustomerMood(communications.get(0).getCustomer(), communications);
        }
    }
    
    public double getAverageSentimentForCustomer(Long customerId) {
        List<Communication> communications = getCommunicationsByCustomer(customerId);
        return sentimentAnalysisService.getAverageSentiment(communications);
    }
    
    private void updateLastContact(Long customerId) {
        customerRepository.findById(customerId).ifPresent(customer -> {
            customer.setLastContact(LocalDateTime.now());
            customerRepository.save(customer);
        });
    }
}