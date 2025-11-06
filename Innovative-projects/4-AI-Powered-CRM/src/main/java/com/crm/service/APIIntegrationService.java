package com.crm.service;

import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;
import org.springframework.http.*;
import java.util.Map;
import java.util.HashMap;

@Service
public class APIIntegrationService {
    
    @Autowired
    private OpenAIService openAIService;
    
    @Value("${api.industry-data.enabled:false}")
    private boolean industryDataEnabled;
    
    @Value("${api.industry-data.url:}")
    private String industryDataUrl;
    
    private final RestTemplate restTemplate = new RestTemplate();
    private final ObjectMapper objectMapper = new ObjectMapper();
    
    public double getIndustryLeadScore(String company, String industry) {
        if (!industryDataEnabled || company == null || company.isEmpty()) {
            return 50.0; // Default score
        }
        
        try {
            // Simulate industry data API call
            Map<String, Object> requestData = new HashMap<>();
            requestData.put("company", company);
            requestData.put("industry", industry);
            
            // For demo purposes, return calculated score based on company characteristics
            return calculateIndustryScore(company, industry);
            
        } catch (Exception e) {
            // Fallback to default scoring
            return 50.0;
        }
    }
    
    public String getCompanyInformation(String companyName) {
        if (companyName == null || companyName.isEmpty()) {
            return "No company information available";
        }
        
        try {
            // Use OpenAI to generate company insights
            String prompt = String.format(
                "Provide brief company information for '%s' including industry, size estimate, and business type in 2-3 sentences.",
                companyName
            );
            
            return openAIService.generateResponse(prompt);
            
        } catch (Exception e) {
            return "Company information unavailable";
        }
    }
    
    public Map<String, Object> getMarketInsights(String industry) {
        Map<String, Object> insights = new HashMap<>();
        
        try {
            // Generate market insights using AI
            String prompt = String.format(
                "Provide market insights for the %s industry including growth trends, key challenges, and opportunities. Format as brief bullet points.",
                industry != null ? industry : "general business"
            );
            
            String aiInsights = openAIService.generateResponse(prompt);
            
            insights.put("insights", aiInsights);
            insights.put("industry", industry);
            insights.put("generated_at", System.currentTimeMillis());
            insights.put("confidence", 0.75);
            
        } catch (Exception e) {
            insights.put("insights", "Market insights unavailable");
            insights.put("error", e.getMessage());
        }
        
        return insights;
    }
    
    public double analyzeSentimentWithAPI(String text) {
        try {
            // Primary: Use OpenAI for sentiment analysis
            return openAIService.analyzeSentiment(text);
            
        } catch (Exception e) {
            // Fallback: Simple keyword-based sentiment analysis
            return performBasicSentimentAnalysis(text);
        }
    }
    
    public Map<String, Object> getCompetitorAnalysis(String company, String industry) {
        Map<String, Object> analysis = new HashMap<>();
        
        try {
            String prompt = String.format(
                "Provide competitive analysis for a company like '%s' in the %s industry. Include main competitors and market positioning in 3-4 sentences.",
                company, industry != null ? industry : "general business"
            );
            
            String aiAnalysis = openAIService.generateResponse(prompt);
            
            analysis.put("analysis", aiAnalysis);
            analysis.put("company", company);
            analysis.put("industry", industry);
            analysis.put("confidence", 0.70);
            
        } catch (Exception e) {
            analysis.put("analysis", "Competitive analysis unavailable");
            analysis.put("error", e.getMessage());
        }
        
        return analysis;
    }
    
    private double calculateIndustryScore(String company, String industry) {
        double score = 50.0; // Base score
        
        // Company size indicators
        if (company.toLowerCase().contains("corp") || 
            company.toLowerCase().contains("corporation") ||
            company.toLowerCase().contains("inc")) {
            score += 15.0;
        }
        
        // Industry multipliers
        if (industry != null) {
            switch (industry.toLowerCase()) {
                case "technology", "software", "saas" -> score += 20.0;
                case "healthcare", "finance", "banking" -> score += 15.0;
                case "manufacturing", "retail" -> score += 10.0;
                case "education", "non-profit" -> score += 5.0;
            }
        }
        
        return Math.min(score, 100.0);
    }
    
    private double performBasicSentimentAnalysis(String text) {
        if (text == null || text.isEmpty()) return 0.0;
        
        String[] positiveWords = {"good", "great", "excellent", "amazing", "wonderful", "fantastic", "love", "like", "happy", "satisfied"};
        String[] negativeWords = {"bad", "terrible", "awful", "hate", "dislike", "angry", "frustrated", "disappointed", "poor", "worst"};
        
        String lowerText = text.toLowerCase();
        int positiveCount = 0;
        int negativeCount = 0;
        
        for (String word : positiveWords) {
            if (lowerText.contains(word)) positiveCount++;
        }
        
        for (String word : negativeWords) {
            if (lowerText.contains(word)) negativeCount++;
        }
        
        if (positiveCount == 0 && negativeCount == 0) return 0.0;
        
        return (double) (positiveCount - negativeCount) / (positiveCount + negativeCount);
    }
}