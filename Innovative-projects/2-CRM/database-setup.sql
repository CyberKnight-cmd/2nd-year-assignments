-- CRM Database Setup Script
-- Run this in MySQL Command Line or MySQL Workbench

CREATE DATABASE IF NOT EXISTS crm_db;
CREATE USER IF NOT EXISTS 'crm_user'@'localhost' IDENTIFIED BY 'password';
GRANT ALL PRIVILEGES ON crm_db.* TO 'crm_user'@'localhost';
FLUSH PRIVILEGES;

-- Verify setup
USE crm_db;
SHOW TABLES;