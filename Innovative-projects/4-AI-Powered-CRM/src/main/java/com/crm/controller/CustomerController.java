package com.crm.controller;

import com.crm.entity.Customer;
import com.crm.service.CustomerService;
import com.crm.service.CommunicationService;
import com.crm.service.RecommendationService;
import com.crm.service.CustomerInsightService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;
import javax.servlet.http.HttpSession;
import java.util.List;
import java.util.Optional;

@Controller
@RequestMapping("/customers")
public class CustomerController {
    
    @Autowired
    private CustomerService customerService;
    
    @Autowired
    private CommunicationService communicationService;
    
    @Autowired
    private RecommendationService recommendationService;
    
    @Autowired
    private CustomerInsightService customerInsightService;
    
    @GetMapping
    public String listCustomers(Model model, HttpSession session) {
        model.addAttribute("customers", customerService.getAllCustomers());
        model.addAttribute("pinnedLeadId", session.getAttribute("pinnedLeadId"));
        return "customers/list";
    }
    
    @GetMapping("/new")
    public String showCreateForm(Model model) {
        model.addAttribute("customer", new Customer());
        return "customers/form";
    }
    
    @PostMapping
    public String saveCustomer(@ModelAttribute Customer customer) {
        customerService.saveCustomer(customer);
        return "redirect:/customers";
    }
    
    @GetMapping("/{id}")
    public String viewCustomer(@PathVariable Long id, Model model) {
        Optional<Customer> customer = customerService.getCustomerById(id);
        if (customer.isPresent()) {
            Customer c = customer.get();
            model.addAttribute("customer", c);
            
            // AI Enhancements
            var communications = communicationService.getCommunicationsByCustomer(id);
            model.addAttribute("communications", communications);
            
            // AI Recommendations
            var recommendations = recommendationService.getPendingRecommendations(id);
            model.addAttribute("recommendations", recommendations);
            
            // Customer Insights
            var insights = customerInsightService.getCustomerInsights(id);
            model.addAttribute("insights", insights);
            
            // Sentiment Analysis
            double avgSentiment = communicationService.getAverageSentimentForCustomer(id);
            model.addAttribute("avgSentiment", avgSentiment);
            
            // Conversion Probability
            double conversionProb = customerService.getConversionProbability(id);
            model.addAttribute("conversionProbability", conversionProb);
            
            return "customers/view";
        }
        return "redirect:/customers";
    }
    
    @GetMapping("/{id}/edit")
    public String showEditForm(@PathVariable Long id, Model model) {
        Optional<Customer> customer = customerService.getCustomerById(id);
        if (customer.isPresent()) {
            model.addAttribute("customer", customer.get());
            return "customers/form";
        }
        return "redirect:/customers";
    }
    
    @PostMapping("/{id}/delete")
    public String deleteCustomer(@PathVariable Long id) {
        customerService.deleteCustomer(id);
        return "redirect:/customers";
    }
    
    @GetMapping("/leads")
    public String listLeads(Model model) {
        model.addAttribute("customers", customerService.getCustomersByStatus("LEAD"));
        return "customers/leads";
    }
    
    @GetMapping("/hot-prospects")
    public String listHotProspects(Model model) {
        try {
            List<Customer> hotProspects = customerService.getHotProspects();
            model.addAttribute("customers", hotProspects);
            model.addAttribute("pageTitle", "Hot Prospects");
            model.addAttribute("pageIcon", "fas fa-fire");
            return "customers/hot-prospects";
        } catch (Exception e) {
            model.addAttribute("error", "Error loading hot prospects: " + e.getMessage());
            return "error";
        }
    }
    
    @GetMapping("/high-risk")
    public String listHighRiskCustomers(Model model) {
        try {
            List<Customer> highRiskCustomers = customerService.getHighRiskCustomers();
            model.addAttribute("customers", highRiskCustomers);
            return "customers/high-risk";
        } catch (Exception e) {
            model.addAttribute("error", "Error loading high risk customers: " + e.getMessage());
            return "error";
        }
    }
    
    @PostMapping("/{id}/score")
    public String updateLeadScore(@PathVariable Long id, @RequestParam Integer score) {
        customerService.updateLeadScore(id, score);
        return "redirect:/customers/" + id;
    }
    
    @PostMapping("/{id}/ai-score")
    public String updateAILeadScore(@PathVariable Long id) {
        customerService.updateAILeadScore(id);
        return "redirect:/customers/" + id;
    }
    
    @PostMapping("/{id}/generate-insights")
    public String generateInsights(@PathVariable Long id) {
        customerService.generateCustomerInsights(id);
        return "redirect:/customers/" + id;
    }
}