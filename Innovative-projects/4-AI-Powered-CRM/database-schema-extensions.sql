-- AI-Powered CRM Database Schema Extensions

-- AI Recommendations Table
CREATE TABLE ai_recommendations (
    id BIGINT AUTO_INCREMENT PRIMARY KEY,
    customer_id BIGINT NOT NULL,
    type VARCHAR(50) NOT NULL,
    recommendation TEXT NOT NULL,
    confidence DECIMAL(3,2),
    status VARCHAR(20) DEFAULT 'PENDING',
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    FOREIGN KEY (customer_id) REFERENCES customers(id) ON DELETE CASCADE
);

-- Customer Insights Table
CREATE TABLE customer_insights (
    id BIGINT AUTO_INCREMENT PRIMARY KEY,
    customer_id BIGINT NOT NULL,
    insight_type VARCHAR(50) NOT NULL,
    insight TEXT NOT NULL,
    sentiment_score DECIMAL(3,2),
    engagement_level INT,
    risk_level VARCHAR(10),
    generated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (customer_id) REFERENCES customers(id) ON DELETE CASCADE
);

-- Sentiment Analysis Table
CREATE TABLE sentiment_analysis (
    id BIGINT AUTO_INCREMENT PRIMARY KEY,
    communication_id BIGINT NOT NULL,
    customer_id BIGINT NOT NULL,
    sentiment_score DECIMAL(3,2) NOT NULL,
    sentiment_label VARCHAR(20),
    confidence DECIMAL(3,2),
    analyzed_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (communication_id) REFERENCES communications(id) ON DELETE CASCADE,
    FOREIGN KEY (customer_id) REFERENCES customers(id) ON DELETE CASCADE
);

-- Predictive Metrics Table
CREATE TABLE predictive_metrics (
    id BIGINT AUTO_INCREMENT PRIMARY KEY,
    customer_id BIGINT NOT NULL,
    metric_type VARCHAR(50) NOT NULL,
    predicted_value DECIMAL(10,2) NOT NULL,
    confidence DECIMAL(3,2),
    timeframe VARCHAR(20),
    prediction_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    valid_until TIMESTAMP,
    FOREIGN KEY (customer_id) REFERENCES customers(id) ON DELETE CASCADE
);

-- Tasks Table (for automation)
CREATE TABLE tasks (
    id BIGINT AUTO_INCREMENT PRIMARY KEY,
    customer_id BIGINT NOT NULL,
    title VARCHAR(255) NOT NULL,
    description TEXT,
    type VARCHAR(50) NOT NULL,
    priority VARCHAR(10) DEFAULT 'MEDIUM',
    status VARCHAR(20) DEFAULT 'PENDING',
    due_date TIMESTAMP,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    ai_generated BOOLEAN DEFAULT FALSE,
    FOREIGN KEY (customer_id) REFERENCES customers(id) ON DELETE CASCADE
);

-- Indexes for performance
CREATE INDEX idx_ai_recommendations_customer ON ai_recommendations(customer_id);
CREATE INDEX idx_ai_recommendations_status ON ai_recommendations(status);
CREATE INDEX idx_customer_insights_customer ON customer_insights(customer_id);
CREATE INDEX idx_customer_insights_type ON customer_insights(insight_type);
CREATE INDEX idx_sentiment_analysis_customer ON sentiment_analysis(customer_id);
CREATE INDEX idx_sentiment_analysis_communication ON sentiment_analysis(communication_id);
CREATE INDEX idx_predictive_metrics_customer ON predictive_metrics(customer_id);
CREATE INDEX idx_predictive_metrics_type ON predictive_metrics(metric_type);
CREATE INDEX idx_tasks_customer ON tasks(customer_id);
CREATE INDEX idx_tasks_status ON tasks(status);
CREATE INDEX idx_tasks_priority ON tasks(priority);
CREATE INDEX idx_tasks_due_date ON tasks(due_date);

-- Sample data for testing
INSERT INTO ai_recommendations (customer_id, type, recommendation, confidence, status) VALUES
(1, 'NEXT_ACTION', 'Schedule follow-up call within 3 days based on high engagement score', 0.85, 'PENDING'),
(2, 'UPSELL', 'Customer ready for premium package upgrade based on usage patterns', 0.78, 'PENDING');

INSERT INTO customer_insights (customer_id, insight_type, insight, sentiment_score, engagement_level, risk_level) VALUES
(1, 'BEHAVIOR', 'High engagement customer with consistent communication patterns', 0.75, 8, 'LOW'),
(2, 'RISK', 'Customer showing decreased engagement, potential churn risk', -0.25, 3, 'HIGH');

INSERT INTO predictive_metrics (customer_id, metric_type, predicted_value, confidence, timeframe, valid_until) VALUES
(1, 'CONVERSION_PROBABILITY', 0.85, 0.80, '30_DAYS', DATE_ADD(NOW(), INTERVAL 30 DAY)),
(1, 'LIFETIME_VALUE', 5000.00, 0.75, '1_YEAR', DATE_ADD(NOW(), INTERVAL 365 DAY)),
(2, 'CHURN_RISK', 0.65, 0.70, '90_DAYS', DATE_ADD(NOW(), INTERVAL 90 DAY));

INSERT INTO tasks (customer_id, title, description, type, priority, due_date, ai_generated) VALUES
(1, 'Follow up with John Doe', 'High-priority lead requires immediate attention', 'CALL', 'HIGH', DATE_ADD(NOW(), INTERVAL 2 HOUR), TRUE),
(2, 'Send retention email', 'Customer showing churn risk signals', 'EMAIL', 'HIGH', DATE_ADD(NOW(), INTERVAL 1 DAY), TRUE);