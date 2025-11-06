package com.crm.controller;

import com.crm.service.AnalyticsService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
@RequestMapping("/analytics")
public class AnalyticsController {
    
    @Autowired
    private AnalyticsService analyticsService;
    
    @GetMapping
    public String showAnalytics(Model model) {
        model.addAttribute("analytics", analyticsService.getDashboardAnalytics());
        model.addAttribute("statusDistribution", analyticsService.getStatusDistribution());
        return "analytics/dashboard";
    }
}