package com.crm.service;

import com.crm.repository.CustomerRepository;
import com.crm.repository.InvoiceRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.math.BigDecimal;
import java.util.HashMap;
import java.util.Map;

@Service
public class AnalyticsService {
    
    @Autowired
    private CustomerRepository customerRepository;
    
    @Autowired
    private InvoiceRepository invoiceRepository;
    
    public Map<String, Object> getDashboardAnalytics() {
        Map<String, Object> analytics = new HashMap<>();
        
        // Customer metrics
        analytics.put("totalCustomers", customerRepository.count());
        analytics.put("leadCount", customerRepository.countByStatus("LEAD"));
        analytics.put("prospectCount", customerRepository.countByStatus("PROSPECT"));
        analytics.put("customerCount", customerRepository.countByStatus("CUSTOMER"));
        
        // Revenue metrics
        BigDecimal totalRevenue = invoiceRepository.getTotalRevenue();
        BigDecimal pendingRevenue = invoiceRepository.getPendingRevenue();
        analytics.put("totalRevenue", totalRevenue != null ? totalRevenue : BigDecimal.ZERO);
        analytics.put("pendingRevenue", pendingRevenue != null ? pendingRevenue : BigDecimal.ZERO);
        
        // Conversion rates
        long totalLeads = customerRepository.countByStatus("LEAD");
        long totalCustomers = customerRepository.countByStatus("CUSTOMER");
        double conversionRate = totalLeads > 0 ? (double) totalCustomers / totalLeads * 100 : 0;
        analytics.put("conversionRate", Math.round(conversionRate * 100.0) / 100.0);
        
        return analytics;
    }
    
    public Map<String, Long> getStatusDistribution() {
        Map<String, Long> distribution = new HashMap<>();
        distribution.put("LEAD", customerRepository.countByStatus("LEAD"));
        distribution.put("PROSPECT", customerRepository.countByStatus("PROSPECT"));
        distribution.put("CUSTOMER", customerRepository.countByStatus("CUSTOMER"));
        distribution.put("INACTIVE", customerRepository.countByStatus("INACTIVE"));
        return distribution;
    }
}