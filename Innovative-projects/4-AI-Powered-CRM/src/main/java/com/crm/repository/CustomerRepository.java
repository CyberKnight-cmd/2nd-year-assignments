package com.crm.repository;

import com.crm.entity.Customer;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;
import java.util.List;

@Repository
public interface CustomerRepository extends JpaRepository<Customer, Long> {
    List<Customer> findByStatus(String status);
    List<Customer> findByEmailContainingIgnoreCase(String email);
    List<Customer> findByFirstNameContainingIgnoreCaseOrLastNameContainingIgnoreCase(String firstName, String lastName);
    
    @Query("SELECT c FROM Customer c ORDER BY c.leadScore DESC")
    List<Customer> findTopLeads();
    
    @Query("SELECT COUNT(c) FROM Customer c WHERE c.status = ?1")
    Long countByStatus(String status);
}