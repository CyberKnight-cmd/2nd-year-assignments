package com.crm.config;

import com.theokanning.openai.service.OpenAiService;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class AIConfig {
    
    @Value("${ai.openai.api-key}")
    private String openAiApiKey;
    
    @Value("${ai.sentiment.enabled:true}")
    private boolean sentimentEnabled;
    
    @Value("${ai.recommendations.enabled:true}")
    private boolean recommendationsEnabled;
    
    @Value("${ai.lead-scoring.enabled:true}")
    private boolean leadScoringEnabled;
    
    @Bean
    public OpenAiService openAiService() {
        return new OpenAiService(openAiApiKey);
    }
    
    public boolean isSentimentEnabled() { return sentimentEnabled; }
    public boolean isRecommendationsEnabled() { return recommendationsEnabled; }
    public boolean isLeadScoringEnabled() { return leadScoringEnabled; }
}