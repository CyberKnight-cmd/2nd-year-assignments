package com.crm.repository;

import com.crm.entity.Communication;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;
import java.util.List;

@Repository
public interface CommunicationRepository extends JpaRepository<Communication, Long> {
    List<Communication> findByCustomerIdOrderByTimestampDesc(Long customerId);
    List<Communication> findByTypeOrderByTimestampDesc(String type);
}