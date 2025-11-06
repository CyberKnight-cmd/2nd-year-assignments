package com.crm.repository;

import com.crm.entity.CustomerInsight;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import java.util.List;

public interface CustomerInsightRepository extends JpaRepository<CustomerInsight, Long> {
    List<CustomerInsight> findByCustomerId(Long customerId);
    List<CustomerInsight> findByInsightType(String insightType);
    
    @Query("SELECT i FROM CustomerInsight i WHERE i.customer.id = ?1 ORDER BY i.generatedAt DESC")
    List<CustomerInsight> findByCustomerIdOrderByGeneratedAtDesc(Long customerId);
    
    @Query("SELECT i FROM CustomerInsight i WHERE i.riskLevel = 'HIGH' ORDER BY i.generatedAt DESC")
    List<CustomerInsight> findHighRiskInsights();
}