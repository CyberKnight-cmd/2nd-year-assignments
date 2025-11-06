# Customer Relationship Management (CRM) System

A comprehensive CRM system built with Spring Boot, MySQL, and Bootstrap for managing customer relationships, tracking interactions, and improving sales processes.

## 🎯 Features

### Core Features
- **👥 Customer Database**: Centralized record of leads, contacts, and clients
- **📧 Communication Tracking**: Log emails, calls, and meetings
- **🧾 Lead Management**: Score and track leads based on conversion potential
- **📈 Sales Pipeline**: Visual representation of sales stages
- **💰 Invoice & Payment Tracking**: Integrated billing management
- **📊 Analytics Dashboard**: Sales trends and customer engagement metrics

### Advanced Features
- Lead scoring system
- Customer status management (Lead → Prospect → Customer)
- Revenue tracking and reporting
- Responsive web interface

## 🛠️ Tech Stack

- **Backend**: Java 17, Spring Boot 3.2.0
- **Database**: MySQL 8.0
- **Frontend**: HTML5, CSS3, JavaScript, Bootstrap 5.3
- **Build Tool**: Maven
- **Template Engine**: Thymeleaf

## 📋 Prerequisites

- Java 17 or higher
- MySQL 8.0 or higher
- Maven 3.6 or higher

## 🚀 Setup Instructions

### 1. Database Setup
```sql
CREATE DATABASE crm_db;
CREATE USER 'crm_user'@'localhost' IDENTIFIED BY 'password';
GRANT ALL PRIVILEGES ON crm_db.* TO 'crm_user'@'localhost';
FLUSH PRIVILEGES;
```

### 2. Configuration
Update `src/main/resources/application.properties` with your database credentials:
```properties
spring.datasource.url=jdbc:mysql://localhost:3306/crm_db
spring.datasource.username=crm_user
spring.datasource.password=your_password
```

### 3. Build and Run
```bash
mvn clean install
mvn spring-boot:run
```

### 4. Access Application
Open your browser and navigate to: `http://localhost:8080`

## 📱 Usage

### Dashboard
- View key metrics: total customers, leads, revenue
- Monitor sales pipeline progress
- Track top-performing leads

### Customer Management
- Add new customers with contact information
- Edit existing customer details
- Track customer status progression
- Manage lead scores

### Lead Management
- View all leads in card format
- Update lead scores in real-time
- Convert leads to prospects/customers

## 🗂️ Project Structure

```
src/
├── main/
│   ├── java/com/crm/
│   │   ├── entity/          # JPA entities
│   │   ├── repository/      # Data access layer
│   │   ├── service/         # Business logic
│   │   ├── controller/      # Web controllers
│   │   └── CrmApplication.java
│   └── resources/
│       ├── templates/       # Thymeleaf templates
│       ├── static/          # CSS, JS, images
│       └── application.properties
```

## 🔧 API Endpoints

- `GET /` - Dashboard
- `GET /customers` - List all customers
- `GET /customers/new` - Add customer form
- `POST /customers` - Save customer
- `GET /customers/{id}` - View customer details
- `GET /customers/{id}/edit` - Edit customer form
- `POST /customers/{id}/delete` - Delete customer
- `GET /customers/leads` - Lead management
- `POST /customers/{id}/score` - Update lead score

## 🎨 UI Components

- **Bootstrap 5.3** for responsive design
- **Font Awesome 6.0** for icons
- **Custom CSS** for CRM-specific styling
- **JavaScript** for form validation and interactions

## 📊 Database Schema

### Customers Table
- id, firstName, lastName, email, phone
- company, status, leadScore
- createdAt, lastContact

### Communications Table
- id, customerId, type, subject, content
- timestamp, direction

### Invoices Table
- id, customerId, invoiceNumber, amount
- issueDate, dueDate, status, description

## 🔮 Future Enhancements

- Email integration for automated communication
- Advanced analytics and reporting
- Mobile app support
- AI-powered lead scoring
- Integration with external CRM tools
- Automated follow-up reminders
- Customer sentiment analysis

## 📄 License

This project is licensed under the MIT License.