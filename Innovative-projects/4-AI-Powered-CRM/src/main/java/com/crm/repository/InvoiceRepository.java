package com.crm.repository;

import com.crm.entity.Invoice;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;
import java.math.BigDecimal;
import java.util.List;

@Repository
public interface InvoiceRepository extends JpaRepository<Invoice, Long> {
    List<Invoice> findByCustomerIdOrderByIssueDateDesc(Long customerId);
    List<Invoice> findByStatus(String status);
    
    @Query("SELECT SUM(i.amount) FROM Invoice i WHERE i.status = 'PAID'")
    BigDecimal getTotalRevenue();
    
    @Query("SELECT SUM(i.amount) FROM Invoice i WHERE i.status = 'PENDING'")
    BigDecimal getPendingRevenue();
}