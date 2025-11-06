-- AI Demo Data for CRM System
-- Run these statements in H2 Console at http://localhost:8080/h2-console


INSERT INTO ai_recommendations (customer_id, type, recommendation, confidence, status, created_at, updated_at) 
VALUES (1, 'NEXT_ACTION', 'Schedule follow-up call within 3 days based on high engagement score', 0.85, 'PENDING', CURRENT_TIMESTAMP, CURRENT_TIMESTAMP);


INSERT INTO ai_recommendations (customer_id, type, recommendation, confidence, status, created_at, updated_at) 
VALUES (2, 'UPSELL', 'Customer ready for premium package upgrade based on usage patterns', 0.78, 'PENDING', CURRENT_TIMESTAMP, CURRENT_TIMESTAMP);


INSERT INTO ai_recommendations (customer_id, type, recommendation, confidence, status, created_at, updated_at) 
VALUES (3, 'FOLLOW_UP', 'Send personalized email - customer showing positive sentiment', 0.72, 'PENDING', CURRENT_TIMESTAMP, CURRENT_TIMESTAMP);


INSERT INTO ai_recommendations (customer_id, type, recommendation, confidence, status, created_at, updated_at) 
VALUES (1, 'CHURN_RISK', 'Monitor closely - decreased activity in last 30 days', 0.65, 'PENDING', CURRENT_TIMESTAMP, CURRENT_TIMESTAMP);


INSERT INTO ai_recommendations (customer_id, type, recommendation, confidence, status, created_at, updated_at) 
VALUES (4, 'CONVERSION', 'High conversion probability - schedule demo call', 0.88, 'PENDING', CURRENT_TIMESTAMP, CURRENT_TIMESTAMP);


INSERT INTO customer_insights (customer_id, insight_type, insight, sentiment_score, engagement_level, risk_level, generated_at) 
VALUES (1, 'BEHAVIOR', 'High engagement customer with consistent communication patterns', 0.75, 8, 'LOW', CURRENT_TIMESTAMP);


INSERT INTO customer_insights (customer_id, insight_type, insight, sentiment_score, engagement_level, risk_level, generated_at) 
VALUES (2, 'RISK', 'Customer showing decreased engagement, potential churn risk', -0.25, 3, 'HIGH', CURRENT_TIMESTAMP);


INSERT INTO customer_insights (customer_id, insight_type, insight, sentiment_score, engagement_level, risk_level, generated_at) 
VALUES (3, 'OPPORTUNITY', 'Strong interest in premium features based on communication analysis', 0.65, 7, 'LOW', CURRENT_TIMESTAMP);


INSERT INTO customer_insights (customer_id, insight_type, insight, sentiment_score, engagement_level, risk_level, generated_at) 
VALUES (4, 'BEHAVIOR', 'New customer with high engagement potential', 0.45, 6, 'MEDIUM', CURRENT_TIMESTAMP);


INSERT INTO customer_insights (customer_id, insight_type, insight, sentiment_score, engagement_level, risk_level, generated_at) 
VALUES (1, 'SENTIMENT', 'Positive sentiment trend over last 30 days', 0.8, 9, 'LOW', CURRENT_TIMESTAMP);


INSERT INTO predictive_analytics (customer_id, metric_type, predicted_value, confidence, timeframe, prediction_date, valid_until) 
VALUES (1, 'CONVERSION_PROBABILITY', 0.85, 0.8, '30_DAYS', CURRENT_TIMESTAMP, DATEADD('DAY', 30, CURRENT_TIMESTAMP));


INSERT INTO predictive_analytics (customer_id, metric_type, predicted_value, confidence, timeframe, prediction_date, valid_until) 
VALUES (1, 'LIFETIME_VALUE', 5000.0, 0.75, '1_YEAR', CURRENT_TIMESTAMP, DATEADD('DAY', 365, CURRENT_TIMESTAMP));


INSERT INTO predictive_analytics (customer_id, metric_type, predicted_value, confidence, timeframe, prediction_date, valid_until) 
VALUES (2, 'CHURN_RISK', 0.75, 0.7, '90_DAYS', CURRENT_TIMESTAMP, DATEADD('DAY', 90, CURRENT_TIMESTAMP));


INSERT INTO predictive_analytics (customer_id, metric_type, predicted_value, confidence, timeframe, prediction_date, valid_until) 
VALUES (2, 'LIFETIME_VALUE', 3200.0, 0.65, '1_YEAR', CURRENT_TIMESTAMP, DATEADD('DAY', 365, CURRENT_TIMESTAMP));


INSERT INTO predictive_analytics (customer_id, metric_type, predicted_value, confidence, timeframe, prediction_date, valid_until) 
VALUES (3, 'CONVERSION_PROBABILITY', 0.92, 0.85, '30_DAYS', CURRENT_TIMESTAMP, DATEADD('DAY', 30, CURRENT_TIMESTAMP));


INSERT INTO predictive_analytics (customer_id, metric_type, predicted_value, confidence, timeframe, prediction_date, valid_until) 
VALUES (3, 'LIFETIME_VALUE', 7500.0, 0.8, '1_YEAR', CURRENT_TIMESTAMP, DATEADD('DAY', 365, CURRENT_TIMESTAMP));


INSERT INTO predictive_analytics (customer_id, metric_type, predicted_value, confidence, timeframe, prediction_date, valid_until) 
VALUES (4, 'CONVERSION_PROBABILITY', 0.68, 0.75, '30_DAYS', CURRENT_TIMESTAMP, DATEADD('DAY', 30, CURRENT_TIMESTAMP));


INSERT INTO predictive_analytics (customer_id, metric_type, predicted_value, confidence, timeframe, prediction_date, valid_until) 
VALUES (4, 'CHURN_RISK', 0.25, 0.7, '90_DAYS', CURRENT_TIMESTAMP, DATEADD('DAY', 90, CURRENT_TIMESTAMP));


INSERT INTO tasks (customer_id, title, description, type, priority, status, due_date, created_at, ai_generated) 
VALUES (1, 'Follow up with John Doe', 'High-priority lead requires immediate attention', 'CALL', 'HIGH', 'PENDING', DATEADD('HOUR', 2, CURRENT_TIMESTAMP), CURRENT_TIMESTAMP, True);


INSERT INTO tasks (customer_id, title, description, type, priority, status, due_date, created_at, ai_generated) 
VALUES (2, 'Send retention email', 'Customer showing churn risk signals', 'EMAIL', 'HIGH', 'PENDING', DATEADD('HOUR', 2, CURRENT_TIMESTAMP), CURRENT_TIMESTAMP, True);


INSERT INTO tasks (customer_id, title, description, type, priority, status, due_date, created_at, ai_generated) 
VALUES (3, 'Schedule demo call', 'Hot prospect ready for product demonstration', 'MEETING', 'HIGH', 'PENDING', DATEADD('HOUR', 2, CURRENT_TIMESTAMP), CURRENT_TIMESTAMP, True);


INSERT INTO tasks (customer_id, title, description, type, priority, status, due_date, created_at, ai_generated) 
VALUES (4, 'Send welcome email', 'New customer onboarding sequence', 'EMAIL', 'MEDIUM', 'PENDING', DATEADD('DAY', 1, CURRENT_TIMESTAMP), CURRENT_TIMESTAMP, True);

