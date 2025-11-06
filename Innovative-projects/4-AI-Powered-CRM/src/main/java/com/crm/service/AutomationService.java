package com.crm.service;

import com.crm.entity.Customer;
import com.crm.entity.Communication;
import com.crm.entity.Task;
import com.crm.repository.TaskRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;
import java.util.List;

@Service
public class AutomationService {
    
    @Autowired
    private TaskRepository taskRepository;
    
    @Autowired
    private RecommendationService recommendationService;
    
    @Autowired
    private MLModelService mlModelService;
    
    public Task createSmartTask(Customer customer, List<Communication> communications) {
        Task task = new Task();
        task.setCustomer(customer);
        task.setAiGenerated(true);
        
        // Determine task type and priority based on customer data
        long daysSinceLastContact = customer.getLastContact() != null ? 
            ChronoUnit.DAYS.between(customer.getLastContact(), LocalDateTime.now()) : 999;
        
        int leadScore = customer.getLeadScore() != null ? customer.getLeadScore() : 0;
        
        if (daysSinceLastContact > 14) {
            task.setType("FOLLOW_UP");
            task.setTitle("Follow up with " + customer.getFullName());
            task.setDescription("Customer hasn't been contacted in " + daysSinceLastContact + " days");
            task.setPriority(leadScore > 70 ? "HIGH" : "MEDIUM");
            task.setDueDate(LocalDateTime.now().plusDays(1));
        } else if (leadScore > 80 && "LEAD".equals(customer.getStatus())) {
            task.setType("CALL");
            task.setTitle("Call hot lead: " + customer.getFullName());
            task.setDescription("High-scoring lead ready for conversion call");
            task.setPriority("HIGH");
            task.setDueDate(LocalDateTime.now().plusHours(4));
        } else {
            task.setType("EMAIL");
            task.setTitle("Send personalized email to " + customer.getFullName());
            task.setDescription("Regular engagement email");
            task.setPriority("LOW");
            task.setDueDate(LocalDateTime.now().plusDays(3));
        }
        
        return taskRepository.save(task);
    }
    
    public void scheduleAutomatedFollowUp(Customer customer, List<Communication> communications) {
        int optimalDays = recommendationService.calculateOptimalFollowUpDays(customer, communications);
        
        Task followUpTask = new Task();
        followUpTask.setCustomer(customer);
        followUpTask.setType("FOLLOW_UP");
        followUpTask.setTitle("Automated follow-up: " + customer.getFullName());
        followUpTask.setDescription("AI-scheduled follow-up based on engagement patterns");
        followUpTask.setPriority(determinePriority(customer));
        followUpTask.setDueDate(LocalDateTime.now().plusDays(optimalDays));
        followUpTask.setAiGenerated(true);
        
        taskRepository.save(followUpTask);
    }
    
    public List<Task> routeLeadsByPriority() {
        return taskRepository.findPendingTasksByPriority();
    }
    
    public void createIntelligentAlert(Customer customer, String alertType, String message) {
        Task alert = new Task();
        alert.setCustomer(customer);
        alert.setType("ALERT");
        alert.setTitle(alertType + " Alert: " + customer.getFullName());
        alert.setDescription(message);
        alert.setPriority("HIGH");
        alert.setDueDate(LocalDateTime.now());
        alert.setAiGenerated(true);
        
        taskRepository.save(alert);
    }
    
    public void processChurnRiskAlerts(List<Customer> customers) {
        for (Customer customer : customers) {
            double churnRisk = mlModelService.predictChurnProbability(customer, List.of());
            
            if (churnRisk > 0.7) {
                createIntelligentAlert(customer, "CHURN_RISK", 
                    String.format("High churn risk (%.1f%%). Immediate intervention required.", churnRisk * 100));
            }
        }
    }
    
    public void processHighValueOpportunities(List<Customer> customers) {
        for (Customer customer : customers) {
            double clv = mlModelService.predictCustomerLifetimeValue(customer, List.of());
            
            if (clv > 5000 && "LEAD".equals(customer.getStatus())) {
                createIntelligentAlert(customer, "HIGH_VALUE", 
                    String.format("High-value opportunity (CLV: $%.0f). Priority engagement recommended.", clv));
            }
        }
    }
    
    public List<Task> getOverdueTasks() {
        return taskRepository.findByStatusAndDueDateBefore("PENDING", LocalDateTime.now());
    }
    
    public List<Task> getAIGeneratedTasks() {
        return taskRepository.findByAiGeneratedTrueAndStatus("PENDING");
    }
    
    public void completeTask(Long taskId) {
        taskRepository.findById(taskId).ifPresent(task -> {
            task.setStatus("COMPLETED");
            taskRepository.save(task);
        });
    }
    
    private String determinePriority(Customer customer) {
        int leadScore = customer.getLeadScore() != null ? customer.getLeadScore() : 0;
        
        if (leadScore > 80) return "HIGH";
        if (leadScore > 60) return "MEDIUM";
        return "LOW";
    }
}