import sqlite3
from datetime import datetime, timedelta
import random
import uuid

def populate_sample_data():
    conn = sqlite3.connect('timemanager.db')
    c = conn.cursor()
    
    # Use fixed demo user ID
    user_id = 'demo-user-12345'
    
    # Clear existing demo data
    print("Clearing existing demo data...")
    c.execute('DELETE FROM pomodoro_sessions WHERE user_id = ?', (user_id,))
    c.execute('DELETE FROM goals WHERE user_id = ?', (user_id,))
    c.execute('DELETE FROM tasks WHERE user_id = ?', (user_id,))
    conn.commit()
    
    # Task templates
    task_templates = [
        ("Write project documentation", "Complete technical documentation for the new feature", "work", 3),
        ("Code review", "Review pull requests from team members", "development", 2),
        ("Team meeting", "Weekly sync with the development team", "work", 2),
        ("Bug fixing", "Fix critical bugs in production", "development", 3),
        ("Email responses", "Respond to client emails", "work", 1),
        ("Research new framework", "Study React hooks and best practices", "learning", 2),
        ("Database optimization", "Optimize slow queries", "development", 3),
        ("Client presentation", "Prepare slides for client demo", "work", 3),
        ("Unit testing", "Write tests for new features", "development", 2),
        ("Design review", "Review UI/UX designs", "work", 1),
        ("Sprint planning", "Plan tasks for next sprint", "work", 2),
        ("Performance analysis", "Analyze application performance", "development", 3),
        ("Documentation update", "Update API documentation", "work", 1),
        ("Refactoring", "Refactor legacy code", "development", 2),
        ("Security audit", "Review security vulnerabilities", "development", 3)
    ]
    
    # Generate data for last 7 days
    today = datetime.now()
    
    print("Populating database with sample data...")
    print(f"User ID: {user_id}\n")
    
    # Get next available IDs
    c.execute('SELECT COALESCE(MAX(id), 0) + 1 FROM tasks')
    task_id_counter = c.fetchone()[0]
    
    c.execute('SELECT COALESCE(MAX(id), 0) + 1 FROM pomodoro_sessions')
    session_id_counter = c.fetchone()[0]
    
    for day_offset in range(7, 0, -1):
        current_date = today - timedelta(days=day_offset)
        date_str = current_date.strftime('%Y-%m-%d')
        
        # Randomly select 4-7 tasks per day
        num_tasks = random.randint(4, 7)
        daily_tasks = random.sample(task_templates, num_tasks)
        
        print(f"Day {8-day_offset} ({date_str}):")
        
        for task_title, task_desc, category, priority in daily_tasks:
            # Random estimated time between 15-90 minutes
            estimated_time = random.choice([15, 25, 30, 45, 60, 90])
            
            # 70% chance task is completed
            is_completed = random.random() < 0.7
            status = 'completed' if is_completed else 'pending'
            
            # Create task timestamp (random hour between 8 AM and 6 PM)
            task_hour = random.randint(8, 18)
            task_time = current_date.replace(hour=task_hour, minute=random.randint(0, 59))
            
            # Insert task
            c.execute('''INSERT INTO tasks (id, user_id, title, description, priority, estimated_time, 
                         deadline, status, category, created_at)
                         VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)''',
                      (task_id_counter, user_id, task_title, task_desc, priority, estimated_time,
                       None, status, category, task_time.isoformat()))
            
            print(f"  - {task_title} ({estimated_time}min, {status})")
            
            # If completed, create pomodoro sessions
            if is_completed:
                # Actual time is usually close to estimated (80-120% of estimate)
                actual_duration = int(estimated_time * random.uniform(0.8, 1.2))
                
                # Create 1-3 pomodoro sessions for this task
                num_sessions = random.randint(1, 3)
                time_per_session = actual_duration // num_sessions
                
                for session_num in range(num_sessions):
                    # Session starts 1-2 hours after task creation
                    session_start = task_time + timedelta(hours=random.randint(1, 2), minutes=random.randint(0, 30))
                    session_end = session_start + timedelta(minutes=time_per_session)
                    
                    c.execute('''INSERT INTO pomodoro_sessions (id, user_id, task_id, duration, 
                                 start_time, end_time, completed, session_type)
                                 VALUES (?, ?, ?, ?, ?, ?, ?, ?)''',
                              (session_id_counter, user_id, task_id_counter, time_per_session,
                               session_start.isoformat(), session_end.isoformat(), 1, 'work'))
                    
                    session_id_counter += 1
            
            task_id_counter += 1
        
        print()
    
    # Add some goals
    goals = [
        ("Complete 30 tasks this month", "Track monthly task completion", 30, random.randint(15, 25)),
        ("Focus for 20 hours", "Accumulate 20 hours of focused work time", 1200, random.randint(800, 1100)),
        ("Learn new technology", "Complete online course", 100, random.randint(40, 70))
    ]
    
    print("Adding goals:")
    for goal_title, goal_desc, target, current in goals:
        deadline = (today + timedelta(days=random.randint(7, 30))).date().isoformat()
        c.execute('''INSERT INTO goals (user_id, title, description, target_value, current_value, 
                     deadline, category, created_at)
                     VALUES (?, ?, ?, ?, ?, ?, ?, ?)''',
                  (user_id, goal_title, goal_desc, target, current, deadline, 'personal', today.isoformat()))
        print(f"  - {goal_title} ({current}/{target})")
    
    conn.commit()
    conn.close()
    
    print(f"\nData population complete!")
    print(f"Total tasks created: {task_id_counter - 1}")
    print(f"Total sessions created: {session_id_counter - 1}")
    print(f"\nYou can now run: python app.py")
    print(f"The AI will analyze this data to provide insights!")

if __name__ == "__main__":
    populate_sample_data()
