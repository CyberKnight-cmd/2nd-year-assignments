import subprocess
import os
import sys
import signal
import time
import threading

PROJECTS = [
    {
        "name": "Time Management Software",
        "path": "1-Time-mamagement-software",
        "command": ["python", "app.py"],
        "port": 5000,
        "type": "flask",
        "populate_script": None
    },
    {
        "name": "CRM System",
        "path": "2-CRM",
        "command": ["mvn", "spring-boot:run"],
        "port": 8081,
        "type": "spring",
        "populate_script": "generate_demo_data.py"
    },
    {
        "name": "AI Productivity Coach",
        "path": "3-AI-Productive-Coach",
        "command": ["python", "app.py"],
        "port": 5001,
        "type": "flask",
        "populate_script": "populate_data.py"
    },
    {
        "name": "AI-Powered CRM",
        "path": "4-AI-Powered-CRM",
        "command": ["mvn", "spring-boot:run"],
        "port": 8082,
        "type": "spring",
        "populate_script": "generate_demo_data.py"
    }
]

def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')

def print_banner(project_name, project_num, total):
    clear_screen()
    print("=" * 70)
    print(f"  EXHIBITION LAUNCHER - Project {project_num}/{total}")
    print("=" * 70)
    print(f"\n  📂 {project_name}\n")
    print("=" * 70)

def populate_database(project_path, script_name):
    """Run database population script after delay"""
    time.sleep(3)
    try:
        print(f"\n📊 Populating database with demo data...")
        result = subprocess.run(
            ["python", script_name],
            cwd=project_path,
            capture_output=True,
            text=True,
            timeout=30
        )
        if result.returncode == 0:
            print(f"✅ Database populated successfully\n")
        else:
            print(f"⚠️  Database population completed with warnings\n")
    except Exception as e:
        print(f"⚠️  Could not populate database: {e}\n")

def run_project(project, project_num, total):
    print_banner(project['name'], project_num, total)
    
    project_path = os.path.join(os.path.dirname(__file__), project['path'])
    
    if not os.path.exists(project_path):
        print(f"\n❌ Error: Project directory not found: {project_path}")
        return False
    
    print(f"\n🚀 Starting {project['name']}...")
    print(f"📍 Location: {project_path}")
    print(f"🌐 URL: http://localhost:{project['port']}")
    if project['populate_script']:
        print(f"📊 Will auto-populate database in 3 seconds...")
    print(f"\n⚡ Press Ctrl+C to stop this project and move to the next one\n")
    print("-" * 70)
    
    process = None
    populate_thread = None
    
    try:
        process = subprocess.Popen(
            project['command'],
            cwd=project_path,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True,
            bufsize=1,
            universal_newlines=True
        )
        
        # Start database population in background if needed
        if project['populate_script']:
            populate_thread = threading.Thread(
                target=populate_database,
                args=(project_path, project['populate_script'])
            )
            populate_thread.daemon = True
            populate_thread.start()
        
        for line in process.stdout:
            print(line, end='')
            
    except KeyboardInterrupt:
        print("\n\n" + "=" * 70)
        print("  ⏸️  Stopping current project...")
        print("=" * 70)
        
        if process:
            if os.name == 'nt':
                subprocess.call(['taskkill', '/F', '/T', '/PID', str(process.pid)], 
                              stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
            else:
                process.terminate()
                try:
                    process.wait(timeout=5)
                except subprocess.TimeoutExpired:
                    process.kill()
        
        return True
    
    except Exception as e:
        print(f"\n❌ Error running project: {e}")
        return False
    
    finally:
        if process and process.poll() is None:
            if os.name == 'nt':
                subprocess.call(['taskkill', '/F', '/T', '/PID', str(process.pid)],
                              stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
            else:
                process.terminate()

def main():
    clear_screen()
    print("=" * 70)
    print("  🎓 EXHIBITION PROJECT LAUNCHER")
    print("=" * 70)
    print(f"\n  Total Projects: {len(PROJECTS)}")
    print("\n  Projects to be demonstrated:")
    for i, proj in enumerate(PROJECTS, 1):
        print(f"    {i}. {proj['name']}")
    
    print("\n" + "=" * 70)
    print("  📋 Instructions:")
    print("  • Press Enter or type 'y' to start each project")
    print("  • Press Ctrl+C to stop current project and move to next")
    print("  • Type 'q' to quit the launcher")
    print("=" * 70)
    
    input("\n\n  Press Enter to begin the exhibition...")
    
    for i, project in enumerate(PROJECTS, 1):
        clear_screen()
        print("=" * 70)
        print(f"  PROJECT {i}/{len(PROJECTS)}: {project['name']}")
        print("=" * 70)
        print(f"\n  Ready to launch: {project['name']}")
        print(f"  Type: {project['type'].upper()}")
        print(f"  Port: {project['port']}")
        
        response = input("\n  Press Enter or type 'y' to start (or 'q' to quit): ").strip().lower()
        
        if response == 'q':
            print("\n  👋 Exiting exhibition launcher...")
            break
        
        if response == '' or response == 'y':
            run_project(project, i, len(PROJECTS))
            
            if i < len(PROJECTS):
                print("\n\n" + "=" * 70)
                print(f"  ✅ Project {i} completed!")
                print(f"  📊 Progress: {i}/{len(PROJECTS)} projects demonstrated")
                print("=" * 70)
                input("\n  Press Enter to continue to next project...")
    
    clear_screen()
    print("=" * 70)
    print("  🎉 EXHIBITION COMPLETE!")
    print("=" * 70)
    print(f"\n  ✅ All {len(PROJECTS)} projects have been demonstrated")
    print("\n  📊 View the comprehensive report at:")
    print("     exhibition_report.html")
    print("\n" + "=" * 70)
    print("\n  Thank you for attending the exhibition! 🎓\n")

if __name__ == "__main__":
    main()
