package com.crm.service;

import org.apache.lucene.analysis.Analyzer;
import org.apache.lucene.analysis.standard.StandardAnalyzer;
import org.apache.lucene.analysis.TokenStream;
import org.apache.lucene.analysis.tokenattributes.CharTermAttribute;
import org.springframework.stereotype.Service;
import java.io.StringReader;
import java.util.*;

@Service
public class TextAnalysisService {
    
    private final Analyzer analyzer = new StandardAnalyzer();
    
    public List<String> extractKeywords(String text) {
        List<String> keywords = new ArrayList<>();
        
        try (TokenStream tokenStream = analyzer.tokenStream("content", new StringReader(text))) {
            CharTermAttribute termAttribute = tokenStream.addAttribute(CharTermAttribute.class);
            tokenStream.reset();
            
            while (tokenStream.incrementToken()) {
                String term = termAttribute.toString();
                if (term.length() > 3 && !isStopWord(term)) {
                    keywords.add(term.toLowerCase());
                }
            }
            tokenStream.end();
        } catch (Exception e) {
            // Log error and return empty list
            return new ArrayList<>();
        }
        
        return keywords;
    }
    
    public Map<String, Integer> getWordFrequency(String text) {
        Map<String, Integer> frequency = new HashMap<>();
        List<String> keywords = extractKeywords(text);
        
        for (String keyword : keywords) {
            frequency.put(keyword, frequency.getOrDefault(keyword, 0) + 1);
        }
        
        return frequency;
    }
    
    public double calculateTextSimilarity(String text1, String text2) {
        Set<String> words1 = new HashSet<>(extractKeywords(text1));
        Set<String> words2 = new HashSet<>(extractKeywords(text2));
        
        Set<String> intersection = new HashSet<>(words1);
        intersection.retainAll(words2);
        
        Set<String> union = new HashSet<>(words1);
        union.addAll(words2);
        
        return union.isEmpty() ? 0.0 : (double) intersection.size() / union.size();
    }
    
    public String categorizeContent(String text) {
        List<String> keywords = extractKeywords(text);
        
        // Simple categorization based on keywords
        if (containsAny(keywords, Arrays.asList("price", "cost", "budget", "payment"))) {
            return "PRICING";
        } else if (containsAny(keywords, Arrays.asList("meeting", "call", "schedule", "appointment"))) {
            return "SCHEDULING";
        } else if (containsAny(keywords, Arrays.asList("problem", "issue", "error", "bug"))) {
            return "SUPPORT";
        } else if (containsAny(keywords, Arrays.asList("interested", "demo", "trial", "evaluation"))) {
            return "SALES";
        } else {
            return "GENERAL";
        }
    }
    
    private boolean isStopWord(String word) {
        Set<String> stopWords = Set.of("the", "and", "or", "but", "in", "on", "at", "to", "for", "of", "with", "by");
        return stopWords.contains(word.toLowerCase());
    }
    
    private boolean containsAny(List<String> keywords, List<String> targets) {
        return keywords.stream().anyMatch(keyword -> 
            targets.stream().anyMatch(target -> keyword.contains(target.toLowerCase())));
    }
}