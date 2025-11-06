-- Quick AI Data Insert (H2 Compatible)

-- High Risk Customers (CHURN_RISK > 0.7)
INSERT INTO predictive_analytics (customer_id, metric_type, predicted_value, confidence, timeframe, prediction_date, valid_until) 
VALUES (2, 'CHURN_RISK', 0.75, 0.7, '90_DAYS', CURRENT_TIMESTAMP, DATEADD('DAY', 90, CURRENT_TIMESTAMP));

-- Hot Prospects (CONVERSION_PROBABILITY > 0.8)
INSERT INTO predictive_analytics (customer_id, metric_type, predicted_value, confidence, timeframe, prediction_date, valid_until) 
VALUES (1, 'CONVERSION_PROBABILITY', 0.85, 0.8, '30_DAYS', CURRENT_TIMESTAMP, DATEADD('DAY', 30, CURRENT_TIMESTAMP));

INSERT INTO predictive_analytics (customer_id, metric_type, predicted_value, confidence, timeframe, prediction_date, valid_until) 
VALUES (3, 'CONVERSION_PROBABILITY', 0.92, 0.85, '30_DAYS', CURRENT_TIMESTAMP, DATEADD('DAY', 30, CURRENT_TIMESTAMP));

-- AI Recommendations
INSERT INTO ai_recommendations (customer_id, type, recommendation, confidence, status, created_at, updated_at) 
VALUES (1, 'NEXT_ACTION', 'Schedule follow-up call within 3 days based on high engagement score', 0.85, 'PENDING', CURRENT_TIMESTAMP, CURRENT_TIMESTAMP);

INSERT INTO ai_recommendations (customer_id, type, recommendation, confidence, status, created_at, updated_at) 
VALUES (2, 'CHURN_RISK', 'Customer at high risk - immediate intervention required', 0.75, 'PENDING', CURRENT_TIMESTAMP, CURRENT_TIMESTAMP);

-- Customer Insights for High Risk
INSERT INTO customer_insights (customer_id, insight_type, insight, sentiment_score, engagement_level, risk_level, generated_at) 
VALUES (2, 'RISK', 'Customer showing decreased engagement, potential churn risk', -0.25, 3, 'HIGH', CURRENT_TIMESTAMP);