package com.crm.config;

import org.springframework.context.annotation.Configuration;
import org.springframework.data.jpa.repository.config.EnableJpaRepositories;
import org.springframework.transaction.annotation.EnableTransactionManagement;
import javax.annotation.PostConstruct;
import org.springframework.beans.factory.annotation.Autowired;
import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.Statement;

@Configuration
@EnableJpaRepositories(basePackages = "com.crm.repository")
@EnableTransactionManagement
public class DatabaseConfig {
    
    @Autowired
    private DataSource dataSource;
    
    @PostConstruct
    public void initializeDatabase() {
        try (Connection connection = dataSource.getConnection();
             Statement statement = connection.createStatement()) {
            
            // Create AI-specific tables if they don't exist
            createAITables(statement);
            
        } catch (Exception e) {
            // Log error but don't fail startup
            System.err.println("Database initialization warning: " + e.getMessage());
        }
    }
    
    private void createAITables(Statement statement) throws Exception {
        // AI Recommendations table
        statement.executeUpdate("""
            CREATE TABLE IF NOT EXISTS ai_recommendations (
                id BIGINT AUTO_INCREMENT PRIMARY KEY,
                customer_id BIGINT NOT NULL,
                type VARCHAR(50) NOT NULL,
                recommendation TEXT NOT NULL,
                confidence DECIMAL(3,2),
                status VARCHAR(20) DEFAULT 'PENDING',
                created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
                updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
            )
        """);
        
        // Customer Insights table
        statement.executeUpdate("""
            CREATE TABLE IF NOT EXISTS customer_insights (
                id BIGINT AUTO_INCREMENT PRIMARY KEY,
                customer_id BIGINT NOT NULL,
                insight_type VARCHAR(50) NOT NULL,
                insight TEXT NOT NULL,
                sentiment_score DECIMAL(3,2),
                engagement_level INT,
                risk_level VARCHAR(10),
                generated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
            )
        """);
        
        // Predictive Analytics table
        statement.executeUpdate("""
            CREATE TABLE IF NOT EXISTS predictive_analytics (
                id BIGINT AUTO_INCREMENT PRIMARY KEY,
                customer_id BIGINT NOT NULL,
                metric_type VARCHAR(50) NOT NULL,
                predicted_value DECIMAL(10,2) NOT NULL,
                confidence DECIMAL(3,2),
                timeframe VARCHAR(20),
                prediction_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
                valid_until TIMESTAMP
            )
        """);
        
        // Tasks table
        statement.executeUpdate("""
            CREATE TABLE IF NOT EXISTS tasks (
                id BIGINT AUTO_INCREMENT PRIMARY KEY,
                customer_id BIGINT NOT NULL,
                title VARCHAR(255) NOT NULL,
                description TEXT,
                type VARCHAR(50) NOT NULL,
                priority VARCHAR(10) DEFAULT 'MEDIUM',
                status VARCHAR(20) DEFAULT 'PENDING',
                due_date TIMESTAMP,
                created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
                ai_generated BOOLEAN DEFAULT FALSE
            )
        """);
    }
}