package com.crm.repository;

import com.crm.entity.PredictiveAnalytics;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import java.util.List;

public interface PredictiveAnalyticsRepository extends JpaRepository<PredictiveAnalytics, Long> {
    List<PredictiveAnalytics> findByCustomerIdAndMetricType(Long customerId, String metricType);
    
    @Query("SELECT p FROM PredictiveAnalytics p WHERE p.metricType = 'CHURN_RISK' AND p.predictedValue > 0.7 ORDER BY p.predictedValue DESC")
    List<PredictiveAnalytics> findHighChurnRiskCustomers();
    
    @Query("SELECT p FROM PredictiveAnalytics p WHERE p.metricType = 'CONVERSION_PROBABILITY' AND p.predictedValue > 0.8 ORDER BY p.predictedValue DESC")
    List<PredictiveAnalytics> findHighConversionProbabilityCustomers();
}