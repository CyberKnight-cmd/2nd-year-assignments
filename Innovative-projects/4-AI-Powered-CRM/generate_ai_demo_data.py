import sqlite3
import random
from datetime import datetime, timedelta

# Connect to H2 database (you'll need to run this when app is running)
# For now, we'll create SQL statements you can run in H2 console

def generate_ai_demo_data():
    sql_statements = []
    
    # Generate AI Recommendations
    recommendations = [
        (1, 'NEXT_ACTION', 'Schedule follow-up call within 3 days based on high engagement score', 0.85, 'PENDING'),
        (2, 'UPSELL', 'Customer ready for premium package upgrade based on usage patterns', 0.78, 'PENDING'),
        (3, 'FOLLOW_UP', 'Send personalized email - customer showing positive sentiment', 0.72, 'PENDING'),
        (1, 'CHURN_RISK', 'Monitor closely - decreased activity in last 30 days', 0.65, 'PENDING'),
        (4, 'CONVERSION', 'High conversion probability - schedule demo call', 0.88, 'PENDING')
    ]
    
    for customer_id, rec_type, recommendation, confidence, status in recommendations:
        sql_statements.append(f"""
INSERT INTO ai_recommendations (customer_id, type, recommendation, confidence, status, created_at, updated_at) 
VALUES ({customer_id}, '{rec_type}', '{recommendation}', {confidence}, '{status}', CURRENT_TIMESTAMP, CURRENT_TIMESTAMP);
""")
    
    # Generate Customer Insights
    insights = [
        (1, 'BEHAVIOR', 'High engagement customer with consistent communication patterns', 0.75, 8, 'LOW'),
        (2, 'RISK', 'Customer showing decreased engagement, potential churn risk', -0.25, 3, 'HIGH'),
        (3, 'OPPORTUNITY', 'Strong interest in premium features based on communication analysis', 0.65, 7, 'LOW'),
        (4, 'BEHAVIOR', 'New customer with high engagement potential', 0.45, 6, 'MEDIUM'),
        (1, 'SENTIMENT', 'Positive sentiment trend over last 30 days', 0.8, 9, 'LOW')
    ]
    
    for customer_id, insight_type, insight, sentiment_score, engagement_level, risk_level in insights:
        sql_statements.append(f"""
INSERT INTO customer_insights (customer_id, insight_type, insight, sentiment_score, engagement_level, risk_level, generated_at) 
VALUES ({customer_id}, '{insight_type}', '{insight}', {sentiment_score}, {engagement_level}, '{risk_level}', CURRENT_TIMESTAMP);
""")
    
    # Generate Predictive Analytics
    predictions = [
        (1, 'CONVERSION_PROBABILITY', 0.85, 0.80, '30_DAYS'),
        (1, 'LIFETIME_VALUE', 5000.00, 0.75, '1_YEAR'),
        (2, 'CHURN_RISK', 0.75, 0.70, '90_DAYS'),
        (2, 'LIFETIME_VALUE', 3200.00, 0.65, '1_YEAR'),
        (3, 'CONVERSION_PROBABILITY', 0.92, 0.85, '30_DAYS'),
        (3, 'LIFETIME_VALUE', 7500.00, 0.80, '1_YEAR'),
        (4, 'CONVERSION_PROBABILITY', 0.68, 0.75, '30_DAYS'),
        (4, 'CHURN_RISK', 0.25, 0.70, '90_DAYS')
    ]
    
    for customer_id, metric_type, predicted_value, confidence, timeframe in predictions:
        valid_until = "DATEADD('DAY', 365, CURRENT_TIMESTAMP)" if timeframe == '1_YEAR' else "DATEADD('DAY', 90, CURRENT_TIMESTAMP)" if timeframe == '90_DAYS' else "DATEADD('DAY', 30, CURRENT_TIMESTAMP)"
        sql_statements.append(f"""
INSERT INTO predictive_analytics (customer_id, metric_type, predicted_value, confidence, timeframe, prediction_date, valid_until) 
VALUES ({customer_id}, '{metric_type}', {predicted_value}, {confidence}, '{timeframe}', CURRENT_TIMESTAMP, {valid_until});
""")
    
    # Generate Tasks
    tasks = [
        (1, 'Follow up with John Doe', 'High-priority lead requires immediate attention', 'CALL', 'HIGH', 'PENDING', True),
        (2, 'Send retention email', 'Customer showing churn risk signals', 'EMAIL', 'HIGH', 'PENDING', True),
        (3, 'Schedule demo call', 'Hot prospect ready for product demonstration', 'MEETING', 'HIGH', 'PENDING', True),
        (4, 'Send welcome email', 'New customer onboarding sequence', 'EMAIL', 'MEDIUM', 'PENDING', True)
    ]
    
    for customer_id, title, description, task_type, priority, status, ai_generated in tasks:
        due_date = "DATEADD('HOUR', 2, CURRENT_TIMESTAMP)" if priority == 'HIGH' else "DATEADD('DAY', 1, CURRENT_TIMESTAMP)"
        sql_statements.append(f"""
INSERT INTO tasks (customer_id, title, description, type, priority, status, due_date, created_at, ai_generated) 
VALUES ({customer_id}, '{title}', '{description}', '{task_type}', '{priority}', '{status}', {due_date}, CURRENT_TIMESTAMP, {ai_generated});
""")
    
    return sql_statements

if __name__ == "__main__":
    statements = generate_ai_demo_data()
    
    with open('ai_demo_data.sql', 'w') as f:
        f.write("-- AI Demo Data for CRM System\n")
        f.write("-- Run these statements in H2 Console at http://localhost:8080/h2-console\n\n")
        for statement in statements:
            f.write(statement + "\n")
    
    print("Generated ai_demo_data.sql - Run this in H2 Console!")
    print("1. Go to http://localhost:8081/h2-console")
    print("2. Use JDBC URL: jdbc:h2:mem:testdb")
    print("3. Username: sa, Password: (empty)")
    print("4. Copy and paste the SQL statements from ai_demo_data.sql")