package com.crm.controller;

import com.crm.service.CustomerService;
import com.crm.service.AnalyticsService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

@Controller
@RequestMapping("/reports")
public class ReportController {
    
    @Autowired
    private CustomerService customerService;
    
    @Autowired
    private AnalyticsService analyticsService;
    
    @GetMapping
    public String showReports(Model model) {
        model.addAttribute("analytics", analyticsService.getDashboardAnalytics());
        return "reports/dashboard";
    }
    
    @GetMapping("/export/csv")
    public ResponseEntity<String> exportCustomersCSV() {
        StringBuilder csv = new StringBuilder();
        csv.append("ID,First Name,Last Name,Email,Phone,Company,Status,Lead Score,Created At\n");
        
        customerService.getAllCustomers().forEach(customer -> {
            csv.append(customer.getId()).append(",")
               .append(customer.getFirstName()).append(",")
               .append(customer.getLastName()).append(",")
               .append(customer.getEmail()).append(",")
               .append(customer.getPhone() != null ? customer.getPhone() : "").append(",")
               .append(customer.getCompany() != null ? customer.getCompany() : "").append(",")
               .append(customer.getStatus()).append(",")
               .append(customer.getLeadScore()).append(",")
               .append(customer.getCreatedAt().format(DateTimeFormatter.ISO_LOCAL_DATE_TIME))
               .append("\n");
        });
        
        String filename = "customers_" + LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyyMMdd_HHmmss")) + ".csv";
        
        return ResponseEntity.ok()
                .header(HttpHeaders.CONTENT_DISPOSITION, "attachment; filename=" + filename)
                .contentType(MediaType.parseMediaType("text/csv"))
                .body(csv.toString());
    }
}