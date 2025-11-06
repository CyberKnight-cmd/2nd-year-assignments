package com.crm.service;

import com.crm.entity.Communication;
import com.crm.repository.CommunicationRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.util.List;

@Service
public class CommunicationService {
    
    @Autowired
    private CommunicationRepository communicationRepository;
    
    @Autowired
    private CustomerService customerService;
    
    public List<Communication> getAllCommunications() {
        return communicationRepository.findAll();
    }
    
    public List<Communication> getCommunicationsByCustomer(Long customerId) {
        return communicationRepository.findByCustomerIdOrderByTimestampDesc(customerId);
    }
    
    public Communication saveCommunication(Communication communication) {
        Communication saved = communicationRepository.save(communication);
        customerService.updateLastContact(communication.getCustomer().getId());
        return saved;
    }
    
    public List<Communication> getRecentCommunications() {
        return communicationRepository.findAll().stream()
                .sorted((c1, c2) -> c2.getTimestamp().compareTo(c1.getTimestamp()))
                .limit(10)
                .toList();
    }
}