package com.crm.controller;

import com.crm.service.*;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import java.util.Map;

@RestController
@RequestMapping("/api/ai")
public class AIController {
    
    @Autowired
    private RecommendationService recommendationService;
    
    @Autowired
    private SentimentAnalysisService sentimentAnalysisService;
    
    @Autowired
    private CustomerInsightService customerInsightService;
    
    @Autowired
    private CustomerService customerService;
    
    @GetMapping("/recommendations/{customerId}")
    public ResponseEntity<?> getRecommendations(@PathVariable Long customerId) {
        var recommendations = recommendationService.getPendingRecommendations(customerId);
        return ResponseEntity.ok(recommendations);
    }
    
    @GetMapping("/sentiment/{customerId}")
    public ResponseEntity<?> getSentiment(@PathVariable Long customerId) {
        var insights = customerInsightService.getCustomerInsights(customerId);
        return ResponseEntity.ok(insights);
    }
    
    @GetMapping("/insights/{customerId}")
    public ResponseEntity<?> getInsights(@PathVariable Long customerId) {
        customerService.generateCustomerInsights(customerId);
        var insights = customerInsightService.getCustomerInsights(customerId);
        return ResponseEntity.ok(insights);
    }
    
    @GetMapping("/conversion-probability/{customerId}")
    public ResponseEntity<?> getConversionProbability(@PathVariable Long customerId) {
        double probability = customerService.getConversionProbability(customerId);
        return ResponseEntity.ok(Map.of("probability", probability));
    }
}