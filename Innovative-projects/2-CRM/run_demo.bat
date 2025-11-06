@echo off
echo Installing Python dependencies...
pip install -r requirements.txt

echo.
echo Starting demo data generation...
echo Make sure your CRM application is running on http://localhost:8080
echo.
pause

python generate_demo_data.py

echo.
echo Demo data generation complete!
pause