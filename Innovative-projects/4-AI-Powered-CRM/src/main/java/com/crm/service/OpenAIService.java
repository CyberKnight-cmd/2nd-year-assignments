package com.crm.service;

import com.theokanning.openai.completion.chat.ChatCompletionRequest;
import com.theokanning.openai.completion.chat.ChatMessage;
import com.theokanning.openai.service.OpenAiService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;
import java.util.List;

@Service
public class OpenAIService {
    
    @Autowired
    private OpenAiService openAiService;
    
    @Value("${ai.openai.model:gpt-3.5-turbo}")
    private String model;
    
    public String generateResponse(String prompt) {
        ChatCompletionRequest request = ChatCompletionRequest.builder()
                .model(model)
                .messages(List.of(new ChatMessage("user", prompt)))
                .maxTokens(150)
                .build();
        
        return openAiService.createChatCompletion(request)
                .getChoices().get(0).getMessage().getContent();
    }
    
    public double analyzeSentiment(String text) {
        String prompt = "Analyze the sentiment of this text and return only a number between -1 (negative) and 1 (positive): " + text;
        String response = generateResponse(prompt);
        try {
            return Double.parseDouble(response.trim());
        } catch (NumberFormatException e) {
            return 0.0;
        }
    }
}