package com.crm.repository;

import com.crm.entity.Task;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import java.time.LocalDateTime;
import java.util.List;

public interface TaskRepository extends JpaRepository<Task, Long> {
    List<Task> findByCustomerIdAndStatus(Long customerId, String status);
    List<Task> findByStatusAndDueDateBefore(String status, LocalDateTime date);
    List<Task> findByAiGeneratedTrueAndStatus(String status);
    
    @Query("SELECT t FROM Task t WHERE t.status = 'PENDING' ORDER BY " +
           "CASE t.priority WHEN 'HIGH' THEN 1 WHEN 'MEDIUM' THEN 2 ELSE 3 END, t.dueDate ASC")
    List<Task> findPendingTasksByPriority();
}