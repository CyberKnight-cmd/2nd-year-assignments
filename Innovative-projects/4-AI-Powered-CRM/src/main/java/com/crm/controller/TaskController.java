package com.crm.controller;

import com.crm.entity.Task;
import com.crm.service.AutomationService;
import com.crm.service.CustomerService;
import com.crm.service.CommunicationService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;
import java.util.List;

@Controller
@RequestMapping("/tasks")
public class TaskController {
    
    @Autowired
    private AutomationService automationService;
    
    @Autowired
    private CustomerService customerService;
    
    @Autowired
    private CommunicationService communicationService;
    
    @GetMapping
    public String listTasks(Model model) {
        List<Task> priorityTasks = automationService.routeLeadsByPriority();
        List<Task> overdueTasks = automationService.getOverdueTasks();
        List<Task> aiTasks = automationService.getAIGeneratedTasks();
        
        model.addAttribute("priorityTasks", priorityTasks);
        model.addAttribute("overdueTasks", overdueTasks);
        model.addAttribute("aiTasks", aiTasks);
        
        return "tasks/list";
    }
    
    @PostMapping("/{id}/complete")
    public String completeTask(@PathVariable Long id) {
        automationService.completeTask(id);
        return "redirect:/tasks";
    }
    
    @PostMapping("/create-smart/{customerId}")
    public String createSmartTask(@PathVariable Long customerId) {
        customerService.getCustomerById(customerId).ifPresent(customer -> {
            var communications = communicationService.getCommunicationsByCustomer(customerId);
            automationService.createSmartTask(customer, communications);
        });
        return "redirect:/customers/" + customerId;
    }
    
    @PostMapping("/schedule-followup/{customerId}")
    public String scheduleFollowUp(@PathVariable Long customerId) {
        customerService.getCustomerById(customerId).ifPresent(customer -> {
            var communications = communicationService.getCommunicationsByCustomer(customerId);
            automationService.scheduleAutomatedFollowUp(customer, communications);
        });
        return "redirect:/customers/" + customerId;
    }
}