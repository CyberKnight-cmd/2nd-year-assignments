package com.crm.controller;

import com.crm.service.CustomerService;
import com.crm.service.AnalyticsService;
import com.crm.service.SentimentAnalysisService;
import com.crm.repository.InvoiceRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import javax.servlet.http.HttpSession;
import java.math.BigDecimal;
import java.util.List;
import com.crm.entity.Customer;

@Controller
public class DashboardController {
    
    @Autowired
    private CustomerService customerService;
    
    @Autowired
    private InvoiceRepository invoiceRepository;
    
    @Autowired
    private AnalyticsService analyticsService;
    
    @Autowired
    private SentimentAnalysisService sentimentAnalysisService;
    
    @GetMapping("/")
    public String dashboard(Model model, HttpSession session) {
        model.addAttribute("totalCustomers", customerService.getAllCustomers().size());
        model.addAttribute("totalLeads", customerService.getCustomerCountByStatus("LEAD"));
        model.addAttribute("totalProspects", customerService.getCustomerCountByStatus("PROSPECT"));
        model.addAttribute("activeCustomers", customerService.getCustomerCountByStatus("CUSTOMER"));
        
        BigDecimal totalRevenue = invoiceRepository.getTotalRevenue();
        BigDecimal pendingRevenue = invoiceRepository.getPendingRevenue();
        
        model.addAttribute("totalRevenue", totalRevenue != null ? totalRevenue : BigDecimal.ZERO);
        model.addAttribute("pendingRevenue", pendingRevenue != null ? pendingRevenue : BigDecimal.ZERO);
        
        // Get top 5 leads and pinned leads
        List<Customer> topLeads = customerService.getTopLeads().stream().limit(5).collect(java.util.stream.Collectors.toList());
        model.addAttribute("topLeads", topLeads);
        
        // Add pinned lead
        Long pinnedLeadId = (Long) session.getAttribute("pinnedLeadId");
        if (pinnedLeadId != null) {
            customerService.getCustomerById(pinnedLeadId).ifPresent(customer -> 
                model.addAttribute("pinnedLead", customer)
            );
        }
        
        // AI Analytics
        var aiAnalytics = analyticsService.getPredictiveAnalytics();
        model.addAttribute("aiAnalytics", aiAnalytics);
        
        // High-risk customers alert
        var highRiskCustomers = customerService.getHighRiskCustomers();
        model.addAttribute("highRiskCount", highRiskCustomers.size());
        model.addAttribute("highRiskCustomers", highRiskCustomers.stream().limit(3).collect(java.util.stream.Collectors.toList()));
        
        return "dashboard";
    }
}