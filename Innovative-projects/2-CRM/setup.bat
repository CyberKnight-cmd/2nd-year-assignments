@echo off
echo Setting up CRM System...

echo.
echo Step 1: Database Setup Required
echo Please run the following SQL commands in MySQL:
echo CREATE DATABASE IF NOT EXISTS crm_db;
echo CREATE USER IF NOT EXISTS 'crm_user'@'localhost' IDENTIFIED BY 'password';
echo GRANT ALL PRIVILEGES ON crm_db.* TO 'crm_user'@'localhost';
echo FLUSH PRIVILEGES;

echo.
echo Step 2: Prerequisites Check
echo Java Version:
java -version

echo.
echo Step 3: Maven Required
echo Please install Maven 3.6+ and add to PATH
echo Download from: https://maven.apache.org/download.cgi

echo.
echo Step 4: After Maven installation, run:
echo mvn clean install
echo mvn spring-boot:run

echo.
echo Step 5: Access application at:
echo http://localhost:8080

pause