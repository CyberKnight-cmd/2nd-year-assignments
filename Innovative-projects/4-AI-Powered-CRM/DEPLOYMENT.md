# AI-Powered CRM Deployment Guide

## Prerequisites

### Required Software
- Java 17 or higher
- Maven 3.6+
- MySQL 8.0+ (or H2 for development)
- OpenAI API Key

### Dependencies Included
- Spring Boot 2.7.18
- OpenAI Java SDK 0.18.2
- Apache Commons Math 3.6.1
- Apache Lucene 9.8.0
- Jackson JSON Processing
- H2 Database (development)
- Thymeleaf Template Engine

## Environment Setup

### 1. Database Configuration
```properties
# For MySQL Production
spring.datasource.url=jdbc:mysql://localhost:3306/ai_crm_db
spring.datasource.username=crm_user
spring.datasource.password=your_password

# For H2 Development (default)
spring.datasource.url=jdbc:h2:mem:testdb
```

### 2. AI Configuration
```properties
# OpenAI API Key (required)
ai.openai.api-key=your-openai-api-key-here

# AI Features Toggle
ai.sentiment.enabled=true
ai.recommendations.enabled=true
ai.lead-scoring.enabled=true
```

### 3. Environment Variables
```bash
export OPENAI_API_KEY=your-actual-api-key
export SPRING_PROFILES_ACTIVE=production
```

## Build and Deploy

### 1. Build Application
```bash
mvn clean install
```

### 2. Run Application
```bash
# Development
mvn spring-boot:run

# Production
java -jar target/ai-powered-crm-system-1.0.0.jar
```

### 3. Database Initialization
The application automatically creates AI tables on startup:
- `ai_recommendations`
- `customer_insights` 
- `predictive_analytics`
- `tasks`

## API Endpoints

### AI Features
- `GET /api/ai/recommendations/{customerId}` - Get AI recommendations
- `GET /api/ai/sentiment/{customerId}` - Get sentiment analysis
- `GET /api/ml/clv/{customerId}` - Customer lifetime value
- `GET /api/ml/churn-risk/{customerId}` - Churn probability

### Task Management
- `GET /tasks` - View intelligent task dashboard
- `POST /tasks/create-smart/{customerId}` - Create AI task
- `POST /tasks/schedule-followup/{customerId}` - Schedule follow-up

## Automated Features

### Background Processing
- **Hourly**: Smart task creation and follow-up scheduling
- **4 Hours**: Churn risk and sentiment alerts
- **Daily**: AI score updates and insight generation

### AI Capabilities
- Smart lead scoring with ML algorithms
- Sentiment analysis of all communications
- Predictive customer lifetime value
- Automated task creation and prioritization
- Intelligent follow-up scheduling

## Monitoring

### Health Checks
- `GET /actuator/health` - Application health
- `GET /actuator/info` - Application info

### Performance Metrics
- Database connection pooling enabled
- Hibernate batch processing configured
- Lucene text analysis optimized

## Security Considerations

### API Keys
- Store OpenAI API key in environment variables
- Never commit API keys to version control
- Use Spring profiles for different environments

### Database Security
- Use strong passwords for database connections
- Enable SSL for production database connections
- Regular backup of AI training data

## Troubleshooting

### Common Issues
1. **OpenAI API Errors**: Check API key validity and rate limits
2. **Database Connection**: Verify connection string and credentials
3. **Memory Issues**: Increase JVM heap size for large datasets

### Logs
```bash
# View application logs
tail -f logs/spring.log

# Enable debug logging
logging.level.com.crm=DEBUG
```

## Production Deployment

### Docker Deployment
```dockerfile
FROM openjdk:17-jre-slim
COPY target/ai-powered-crm-system-1.0.0.jar app.jar
EXPOSE 8080
ENTRYPOINT ["java","-jar","/app.jar"]
```

### Cloud Deployment
- AWS: Use RDS for MySQL, EC2 for application
- Azure: Use Azure Database for MySQL, App Service
- GCP: Use Cloud SQL, App Engine

## Performance Optimization

### Database Indexing
All AI tables include optimized indexes for:
- Customer lookups
- Status filtering  
- Date range queries
- Priority sorting

### Caching
- Enable Spring Cache for frequently accessed data
- Use Redis for distributed caching in production

### Scaling
- Horizontal scaling supported
- Stateless design enables load balancing
- Background tasks can run on separate instances