#!/usr/bin/env python3
"""
Test script for AI features in the Productivity Coach
"""

from ai_services import AICoach
import sqlite3

def test_ai_features():
    print("Testing AI Productivity Coach Features\n")
    
    # Initialize AI Coach
    coach = AICoach()
    
    # Test 1: Natural Language Parsing
    print("1. Natural Language Task Parsing")
    test_inputs = [
        "Finish project report by Friday, high priority, should take 2 hours",
        "Call client tomorrow, urgent, 30 minutes",
        "Review code, low priority, 45 mins",
        "Meeting prep for next week, 1 hour"
    ]
    
    for text in test_inputs:
        parsed = coach.parse_natural_language_task(text)
        print(f"   Input: '{text}'")
        print(f"   -> Title: {parsed['title']}")
        print(f"   -> Priority: {parsed['priority']} | Time: {parsed['estimated_time']}min | Deadline: {parsed['deadline']}")
        print()
    
    # Test 2: Smart Time Estimation
    print("2. Smart Time Estimation")
    test_tasks = [
        ("Write documentation", "work", 2),
        ("Code review", "development", 3),
        ("Team meeting", "work", 1),
        ("Bug fix", "development", 3)
    ]
    
    for title, category, priority in test_tasks:
        estimate = coach.get_smart_estimate(title, category, priority)
        print(f"   '{title}' ({category}, priority {priority}) -> {estimate} minutes")
    
    print("\n3. Productivity Analysis")
    print("   Note: Requires actual user data in database for meaningful results")
    
    # Create sample data for testing
    conn = sqlite3.connect('timemanager.db')
    c = conn.cursor()
    
    # Check if we have any data
    c.execute('SELECT COUNT(*) FROM tasks')
    task_count = c.fetchone()[0]
    
    c.execute('SELECT COUNT(*) FROM pomodoro_sessions')
    session_count = c.fetchone()[0]
    
    print(f"   Current database: {task_count} tasks, {session_count} sessions")
    
    if task_count > 0:
        # Test with first user
        c.execute('SELECT DISTINCT user_id FROM tasks LIMIT 1')
        result = c.fetchone()
        if result:
            user_id = result[0]
            insights = coach.get_productivity_insights(user_id)
            print(f"   Peak hour: {insights['peak_hours']['peak_hour']}:00")
            print(f"   Completion rate: {insights['completion_patterns']['completion_rate']}%")
            print(f"   Trend: {insights['completion_patterns']['trend']}")
            if insights['insights']:
                print(f"   AI Tip: {insights['insights'][0]}")
    
    conn.close()
    print("\nAI Feature Testing Complete!")

if __name__ == "__main__":
    test_ai_features()