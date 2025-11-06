package com.crm.controller;

import com.crm.entity.Customer;
import com.crm.service.CustomerService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;
import javax.servlet.http.HttpSession;
import java.util.Optional;

@Controller
@RequestMapping("/customers")
public class CustomerController {
    
    @Autowired
    private CustomerService customerService;
    
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
            model.addAttribute("customer", customer.get());
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
    
    @PostMapping("/{id}/score")
    public String updateLeadScore(@PathVariable Long id, @RequestParam Integer score) {
        customerService.updateLeadScore(id, score);
        return "redirect:/customers/" + id;
    }
}