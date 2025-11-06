import requests
import json
import random
from faker import Faker

fake = Faker()

# CRM API endpoint
BASE_URL = "http://localhost:8082"

# Demo data configuration
TOTAL_CUSTOMERS = 100
STATUSES = ["LEAD", "PROSPECT", "CUSTOMER", "INACTIVE"]
STATUS_WEIGHTS = [0.4, 0.3, 0.25, 0.05]  # 40% leads, 30% prospects, 25% customers, 5% inactive

def generate_customer():
    """Generate a single customer with realistic data"""
    status = random.choices(STATUSES, weights=STATUS_WEIGHTS)[0]
    
    # Lead score based on status
    if status == "CUSTOMER":
        lead_score = random.randint(75, 100)
    elif status == "PROSPECT":
        lead_score = random.randint(50, 85)
    elif status == "LEAD":
        lead_score = random.randint(10, 60)
    else:  # INACTIVE
        lead_score = random.randint(0, 25)
    
    return {
        "firstName": fake.first_name(),
        "lastName": fake.last_name(),
        "email": fake.email(),
        "phone": fake.phone_number(),
        "company": fake.company() if random.random() > 0.2 else None,
        "status": status,
        "leadScore": lead_score
    }

def create_customer(customer_data):
    """Send POST request to create customer"""
    try:
        response = requests.post(
            f"{BASE_URL}/customers",
            data=customer_data,
            headers={"Content-Type": "application/x-www-form-urlencoded"}
        )
        return response.status_code == 302  # Redirect on success
    except Exception as e:
        print(f"Error creating customer: {e}")
        return False

def main():
    print("🚀 Generating demo customers for CRM Pro...")
    print(f"📊 Creating {TOTAL_CUSTOMERS} customers with realistic distribution:")
    print(f"   • {int(TOTAL_CUSTOMERS * STATUS_WEIGHTS[0])} Leads")
    print(f"   • {int(TOTAL_CUSTOMERS * STATUS_WEIGHTS[1])} Prospects") 
    print(f"   • {int(TOTAL_CUSTOMERS * STATUS_WEIGHTS[2])} Customers")
    print(f"   • {int(TOTAL_CUSTOMERS * STATUS_WEIGHTS[3])} Inactive")
    print()
    
    success_count = 0
    
    for i in range(TOTAL_CUSTOMERS):
        customer = generate_customer()
        
        if create_customer(customer):
            success_count += 1
            print(f"✅ Created: {customer['firstName']} {customer['lastName']} ({customer['status']}) - Score: {customer['leadScore']}")
        else:
            print(f"❌ Failed: {customer['firstName']} {customer['lastName']}")
        
        # Progress indicator
        if (i + 1) % 10 == 0:
            print(f"📈 Progress: {i + 1}/{TOTAL_CUSTOMERS} customers processed")
    
    print(f"\n🎉 Demo data generation complete!")
    print(f"✅ Successfully created: {success_count}/{TOTAL_CUSTOMERS} customers")
    print(f"🌐 Visit http://localhost:8082 to see your populated CRM!")

if __name__ == "__main__":
    main()