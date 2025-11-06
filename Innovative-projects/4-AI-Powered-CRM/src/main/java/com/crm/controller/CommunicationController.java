package com.crm.controller;

import com.crm.entity.Communication;
import com.crm.entity.Customer;
import com.crm.service.CommunicationService;
import com.crm.service.CustomerService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;
import java.util.Optional;

@Controller
@RequestMapping("/communications")
public class CommunicationController {
    
    @Autowired
    private CommunicationService communicationService;
    
    @Autowired
    private CustomerService customerService;
    
    @GetMapping
    public String listCommunications(Model model) {
        model.addAttribute("communications", communicationService.getAllCommunications());
        return "communications/list";
    }
    
    @GetMapping("/new")
    public String showCreateForm(@RequestParam(required = false) Long customerId,
                                @RequestParam(required = false) String type,
                                @RequestParam(required = false) String direction,
                                @RequestParam(required = false) String subject,
                                @RequestParam(required = false) String content,
                                Model model) {
        Communication communication = new Communication();
        
        if (customerId != null) {
            Optional<Customer> customer = customerService.getCustomerById(customerId);
            if (customer.isPresent()) {
                communication.setCustomer(customer.get());
                
                // Generate AI content for hot prospects
                if ("Hot Prospect Follow-up".equals(subject) && customer.get().getLeadScore() != null && customer.get().getLeadScore() > 80) {
                    String aiContent = generateHotProspectEmail(customer.get());
                    communication.setContent(aiContent);
                }
            }
        }
        if (type != null) communication.setType(type);
        if (direction != null) communication.setDirection(direction);
        if (subject != null) communication.setSubject(subject);
        if (content != null && communication.getContent() == null) communication.setContent(content);
        
        model.addAttribute("communication", communication);
        model.addAttribute("customers", customerService.getAllCustomers());
        return "communications/form";
    }
    
    @PostMapping
    public String saveCommunication(@ModelAttribute Communication communication) {
        communicationService.saveCommunication(communication);
        return "redirect:/communications";
    }
    
    @GetMapping("/customer/{customerId}")
    public String getCustomerCommunications(@PathVariable Long customerId, Model model) {
        Optional<Customer> customer = customerService.getCustomerById(customerId);
        if (customer.isPresent()) {
            model.addAttribute("customer", customer.get());
            model.addAttribute("communications", communicationService.getCommunicationsByCustomer(customerId));
            return "communications/customer";
        }
        return "redirect:/customers";
    }
    
    private String generateHotProspectEmail(Customer customer) {
        String company = customer.getCompany() != null ? customer.getCompany() : "your business";
        
        return String.format("Hi %s,\n\n" +
            "I hope this email finds you well! Based on your exceptional engagement, our AI system has identified you as a high-priority prospect.\n\n" +
            "Given your strong interest and %s's potential, I believe now is the perfect time to move forward with a personalized solution.\n\n" +
            "I would love to schedule a priority consultation to:\n" +
            "• Discuss your specific goals and challenges\n" +
            "• Present a customized solution designed for your needs\n" +
            "• Explore exclusive offers for qualified prospects\n" +
            "• Show you how we can accelerate your success\n\n" +
            "As a hot prospect, you qualify for:\n" +
            "• Priority scheduling and dedicated support\n" +
            "• Exclusive pricing options\n" +
            "• Fast-track implementation\n" +
            "• Complimentary consultation worth $500\n\n" +
            "Available time slots:\n" +
            "• Tomorrow at 2:00 PM\n" +
            "• Wednesday at 10:00 AM\n" +
            "• Thursday at 3:00 PM\n\n" +
            "Which time works best for you?\n\n" +
            "Best regards,\n" +
            "Sales Team",
            customer.getFirstName(), company);
    }
}