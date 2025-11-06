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
    public String showCreateForm(@RequestParam(required = false) Long customerId, Model model) {
        Communication communication = new Communication();
        if (customerId != null) {
            Optional<Customer> customer = customerService.getCustomerById(customerId);
            customer.ifPresent(communication::setCustomer);
        }
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
}