package com.crm.repository;

import com.crm.entity.AIRecommendation;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import java.util.List;

public interface AIRecommendationRepository extends JpaRepository<AIRecommendation, Long> {
    List<AIRecommendation> findByCustomerIdAndStatus(Long customerId, String status);
    List<AIRecommendation> findByStatus(String status);
    
    @Query("SELECT r FROM AIRecommendation r WHERE r.customer.id = ?1 ORDER BY r.createdAt DESC")
    List<AIRecommendation> findByCustomerIdOrderByCreatedAtDesc(Long customerId);
}