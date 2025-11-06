package com.crm.controller;

import com.crm.service.MLModelService;
import com.crm.service.CustomerService;
import com.crm.service.CommunicationService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import java.util.Map;

@RestController
@RequestMapping("/api/ml")
public class MLController {
    
    @Autowired
    private MLModelService mlModelService;
    
    @Autowired
    private CustomerService customerService;
    
    @Autowired
    private CommunicationService communicationService;
    
    @GetMapping("/clv/{customerId}")
    public ResponseEntity<?> getCustomerLifetimeValue(@PathVariable Long customerId) {
        return customerService.getCustomerById(customerId)
                .map(customer -> {
                    var communications = communicationService.getCommunicationsByCustomer(customerId);
                    double clv = mlModelService.predictCustomerLifetimeValue(customer, communications);
                    return ResponseEntity.ok(Map.of("clv", clv));
                })
                .orElse(ResponseEntity.notFound().build());
    }
    
    @GetMapping("/churn-risk/{customerId}")
    public ResponseEntity<?> getChurnRisk(@PathVariable Long customerId) {
        return customerService.getCustomerById(customerId)
                .map(customer -> {
                    var communications = communicationService.getCommunicationsByCustomer(customerId);
                    double churnRisk = mlModelService.predictChurnProbability(customer, communications);
                    return ResponseEntity.ok(Map.of("churnRisk", churnRisk));
                })
                .orElse(ResponseEntity.notFound().build());
    }
    
    @GetMapping("/contact-time/{customerId}")
    public ResponseEntity<?> getOptimalContactTime(@PathVariable Long customerId) {
        return customerService.getCustomerById(customerId)
                .map(customer -> {
                    var communications = communicationService.getCommunicationsByCustomer(customerId);
                    String optimalTime = mlModelService.predictOptimalContactTime(customer, communications);
                    return ResponseEntity.ok(Map.of("optimalTime", optimalTime));
                })
                .orElse(ResponseEntity.notFound().build());
    }
    
    @GetMapping("/product-recommendation/{customerId}")
    public ResponseEntity<?> getProductRecommendation(@PathVariable Long customerId) {
        return customerService.getCustomerById(customerId)
                .map(customer -> {
                    var communications = communicationService.getCommunicationsByCustomer(customerId);
                    String recommendation = mlModelService.generateProductRecommendation(customer, communications);
                    return ResponseEntity.ok(Map.of("recommendation", recommendation));
                })
                .orElse(ResponseEntity.notFound().build());
    }
    
    @GetMapping("/engagement-score/{customerId}")
    public ResponseEntity<?> getEngagementScore(@PathVariable Long customerId) {
        return customerService.getCustomerById(customerId)
                .map(customer -> {
                    var communications = communicationService.getCommunicationsByCustomer(customerId);
                    double engagementScore = mlModelService.calculateEngagementScore(customer, communications);
                    return ResponseEntity.ok(Map.of("engagementScore", engagementScore));
                })
                .orElse(ResponseEntity.notFound().build());
    }
}