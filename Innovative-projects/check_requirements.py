import subprocess
import sys
import os

def check_command(command, name):
    """Check if a command is available"""
    try:
        result = subprocess.run(
            [command, '--version'],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        print(f"✅ {name}: Available")
        return True
    except FileNotFoundError:
        print(f"❌ {name}: NOT FOUND")
        return False

def check_port(port):
    """Check if a port is available"""
    try:
        result = subprocess.run(
            ['netstat', '-ano'],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        if f':{port}' in result.stdout:
            print(f"⚠️  Port {port}: IN USE (may need to be freed)")
            return False
        else:
            print(f"✅ Port {port}: Available")
            return True
    except:
        print(f"⚠️  Port {port}: Could not check")
        return True

def check_project_files():
    """Check if project directories exist"""
    projects = [
        "1-Time-mamagement-software",
        "2-CRM",
        "3-AI-Productive-Coach",
        "4-AI-Powered-CRM"
    ]
    
    all_exist = True
    for project in projects:
        path = os.path.join(os.path.dirname(__file__), project)
        if os.path.exists(path):
            print(f"✅ {project}: Found")
        else:
            print(f"❌ {project}: NOT FOUND")
            all_exist = False
    
    return all_exist

def main():
    print("=" * 70)
    print("  EXHIBITION SYSTEM - REQUIREMENTS CHECK")
    print("=" * 70)
    
    print("\n📋 Checking Required Software:\n")
    python_ok = check_command('python', 'Python')
    java_ok = check_command('java', 'Java')
    mvn_ok = check_command('mvn', 'Maven')
    
    print("\n🔌 Checking Ports:\n")
    port_5000_ok = check_port(5000)
    port_5001_ok = check_port(5001)
    port_8081_ok = check_port(8081)
    port_8082_ok = check_port(8082)
    
    print("\n📁 Checking Project Directories:\n")
    projects_ok = check_project_files()
    
    print("\n" + "=" * 70)
    print("  SUMMARY")
    print("=" * 70)
    
    all_ok = python_ok and java_ok and mvn_ok and projects_ok
    
    if all_ok:
        print("\n✅ All requirements met! You're ready for the exhibition.")
        if not (port_5000_ok and port_5001_ok and port_8081_ok and port_8082_ok):
            print("\n⚠️  Note: Some ports are in use. You may need to free them.")
            print("   Use 'netstat -ano | findstr :<port>' to find processes")
            print("   Use 'taskkill /PID <PID> /F' to kill them")
    else:
        print("\n❌ Some requirements are missing. Please install:")
        if not python_ok:
            print("   - Python: https://www.python.org/downloads/")
        if not java_ok:
            print("   - Java 17+: https://adoptium.net/")
        if not mvn_ok:
            print("   - Maven: https://maven.apache.org/download.cgi")
        if not projects_ok:
            print("   - Ensure all project directories are present")
    
    print("\n" + "=" * 70)
    input("\nPress Enter to exit...")

if __name__ == "__main__":
    main()
