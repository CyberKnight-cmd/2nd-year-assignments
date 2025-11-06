@echo off
echo Killing any process on port 8081...
for /f "tokens=5" %%a in ('netstat -ano ^| findstr :8081') do (
    taskkill /PID %%a /F >nul 2>&1
)

echo Starting AI-Powered CRM on port 8081...
mvn spring-boot:run