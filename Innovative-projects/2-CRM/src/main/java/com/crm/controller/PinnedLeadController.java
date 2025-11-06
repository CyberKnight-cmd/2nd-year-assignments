package com.crm.controller;

import com.crm.service.CustomerService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import javax.servlet.http.HttpSession;

@Controller
public class PinnedLeadController {
    
    @Autowired
    private CustomerService customerService;
    
    @PostMapping("/pin-lead")
    @ResponseBody
    public String pinLead(@RequestParam Long customerId, HttpSession session) {
        session.setAttribute("pinnedLeadId", customerId);
        return "success";
    }
    
    @PostMapping("/unpin-lead")
    @ResponseBody
    public String unpinLead(HttpSession session) {
        session.removeAttribute("pinnedLeadId");
        return "success";
    }
}