from flask import Flask, render_template, request, jsonify, session, redirect, url_for
from datetime import datetime, timedelta
import sqlite3
import json
import uuid
from functools import wraps

app = Flask(__name__)
app.secret_key = 'time_manager_secret_key_2024'
app.permanent_session_lifetime = timedelta(days=30)

def init_db():
    conn = sqlite3.connect('timemanager.db')
    c = conn.cursor()
    
    # Drop existing tables to recreate with new schema
    c.execute('DROP TABLE IF EXISTS tasks')
    c.execute('DROP TABLE IF EXISTS pomodoro_sessions')
    c.execute('DROP TABLE IF EXISTS goals')
    
    c.execute('''CREATE TABLE tasks (
        id INTEGER PRIMARY KEY,
        user_id TEXT NOT NULL,
        title TEXT NOT NULL,
        description TEXT,
        priority INTEGER DEFAULT 1,
        estimated_time INTEGER,
        deadline TEXT,
        status TEXT DEFAULT 'pending',
        category TEXT DEFAULT 'work',
        created_at TEXT DEFAULT CURRENT_TIMESTAMP
    )''')
    
    c.execute('''CREATE TABLE pomodoro_sessions (
        id INTEGER PRIMARY KEY,
        user_id TEXT NOT NULL,
        task_id INTEGER,
        duration INTEGER,
        start_time TEXT,
        end_time TEXT,
        completed BOOLEAN DEFAULT 0,
        session_type TEXT DEFAULT 'work'
    )''')
    
    c.execute('''CREATE TABLE goals (
        id INTEGER PRIMARY KEY,
        user_id TEXT NOT NULL,
        title TEXT NOT NULL,
        description TEXT,
        target_value INTEGER,
        current_value INTEGER DEFAULT 0,
        deadline TEXT,
        category TEXT DEFAULT 'personal',
        created_at TEXT DEFAULT CURRENT_TIMESTAMP
    )''')
    
    conn.commit()
    conn.close()

def require_session(f):
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if 'user_id' not in session:
            session['user_id'] = str(uuid.uuid4())
        return f(*args, **kwargs)
    return decorated_function

@app.route('/')
@require_session
def index():
    return render_template('dashboard.html')

@app.route('/tasks')
@require_session
def tasks_page():
    return render_template('tasks.html')

@app.route('/analytics')
@require_session
def analytics_page():
    return render_template('analytics.html')

@app.route('/goals')
@require_session
def goals_page():
    return render_template('goals.html')

@app.route('/pomodoro')
@require_session
def pomodoro_page():
    return render_template('pomodoro.html')

@app.route('/api/tasks', methods=['GET', 'POST'])
@require_session
def tasks():
    conn = sqlite3.connect('timemanager.db')
    c = conn.cursor()
    user_id = session['user_id']
    
    if request.method == 'POST':
        data = request.json
        c.execute('''INSERT INTO tasks (user_id, title, description, priority, estimated_time, deadline, category)
                     VALUES (?, ?, ?, ?, ?, ?, ?)''',
                  (user_id, data['title'], data.get('description', ''), data.get('priority', 1),
                   data.get('estimated_time', 30), data.get('deadline'), data.get('category', 'work')))
        conn.commit()
        task_id = c.lastrowid
        conn.close()
        return jsonify({'id': task_id, 'status': 'created'})
    
    c.execute('SELECT * FROM tasks WHERE user_id = ? ORDER BY priority DESC, deadline ASC', (user_id,))
    tasks = [dict(zip([col[0] for col in c.description], row)) for row in c.fetchall()]
    
    # Add sample tasks if no tasks exist
    if not tasks:
        from datetime import date, timedelta
        sample_tasks = [
            {'id': 1, 'title': 'Complete project proposal', 'description': 'Write and review the Q4 project proposal', 'priority': 3, 'estimated_time': 45, 'status': 'pending', 'category': 'work'},
            {'id': 2, 'title': 'Team meeting preparation', 'description': 'Prepare slides for weekly team sync', 'priority': 2, 'estimated_time': 30, 'status': 'completed', 'category': 'work'},
            {'id': 3, 'title': 'Code review', 'description': 'Review pull requests from team members', 'priority': 2, 'estimated_time': 25, 'status': 'pending', 'category': 'development'},
            {'id': 4, 'title': 'Exercise routine', 'description': 'Morning workout session', 'priority': 1, 'estimated_time': 60, 'status': 'completed', 'category': 'personal'},
            {'id': 5, 'title': 'Learn new framework', 'description': 'Study React hooks documentation', 'priority': 2, 'estimated_time': 90, 'status': 'pending', 'category': 'learning'}
        ]
        tasks = sample_tasks
    
    conn.close()
    return jsonify(tasks)

@app.route('/api/tasks/<int:task_id>', methods=['PUT', 'DELETE'])
@require_session
def task_detail(task_id):
    conn = sqlite3.connect('timemanager.db')
    c = conn.cursor()
    user_id = session['user_id']
    
    if request.method == 'PUT':
        data = request.json
        c.execute('UPDATE tasks SET status = ? WHERE id = ? AND user_id = ?', 
                  (data['status'], task_id, user_id))
        conn.commit()
    elif request.method == 'DELETE':
        c.execute('DELETE FROM tasks WHERE id = ? AND user_id = ?', (task_id, user_id))
        conn.commit()
    
    conn.close()
    return jsonify({'status': 'success'})

@app.route('/api/pomodoro', methods=['POST'])
@require_session
def pomodoro_session():
    data = request.json
    conn = sqlite3.connect('timemanager.db')
    c = conn.cursor()
    user_id = session['user_id']
    
    c.execute('''INSERT INTO pomodoro_sessions (user_id, task_id, duration, start_time, end_time, completed, session_type)
                 VALUES (?, ?, ?, ?, ?, ?, ?)''',
              (user_id, data.get('task_id'), data['duration'], data.get('start_time', datetime.now().isoformat()),
               datetime.now().isoformat(), data.get('completed', False), data.get('session_type', 'work')))
    conn.commit()
    conn.close()
    return jsonify({'status': 'session_logged'})

@app.route('/api/analytics')
@require_session
def analytics():
    conn = sqlite3.connect('timemanager.db')
    c = conn.cursor()
    user_id = session['user_id']
    
    # Get completed tasks by day
    c.execute('''SELECT DATE(created_at) as date, COUNT(*) as count 
                 FROM tasks WHERE user_id = ? AND status = 'completed' 
                 GROUP BY DATE(created_at) ORDER BY date DESC LIMIT 7''', (user_id,))
    daily_tasks = [dict(zip([col[0] for col in c.description], row)) for row in c.fetchall()]
    
    # Get pomodoro sessions (including incomplete ones)
    c.execute('''SELECT DATE(start_time) as date, SUM(duration) as total_time
                 FROM pomodoro_sessions WHERE user_id = ?
                 GROUP BY DATE(start_time) ORDER BY date DESC LIMIT 7''', (user_id,))
    daily_time = [dict(zip([col[0] for col in c.description], row)) for row in c.fetchall()]
    
    # Get productivity stats
    c.execute('SELECT COUNT(*) FROM tasks WHERE user_id = ? AND status = "completed"', (user_id,))
    total_completed = c.fetchone()[0]
    
    c.execute('SELECT SUM(duration) FROM pomodoro_sessions WHERE user_id = ?', (user_id,))
    total_focus_time = c.fetchone()[0] or 0
    
    # Add sample data if no data exists
    if not daily_tasks and not daily_time:
        from datetime import date, timedelta
        today = date.today()
        
        daily_tasks = [
            {'date': (today - timedelta(days=6)).isoformat(), 'count': 3},
            {'date': (today - timedelta(days=5)).isoformat(), 'count': 5},
            {'date': (today - timedelta(days=4)).isoformat(), 'count': 2},
            {'date': (today - timedelta(days=3)).isoformat(), 'count': 7},
            {'date': (today - timedelta(days=2)).isoformat(), 'count': 4},
            {'date': (today - timedelta(days=1)).isoformat(), 'count': 6},
            {'date': today.isoformat(), 'count': 3}
        ]
        
        daily_time = [
            {'date': (today - timedelta(days=6)).isoformat(), 'total_time': 75},
            {'date': (today - timedelta(days=5)).isoformat(), 'total_time': 125},
            {'date': (today - timedelta(days=4)).isoformat(), 'total_time': 50},
            {'date': (today - timedelta(days=3)).isoformat(), 'total_time': 175},
            {'date': (today - timedelta(days=2)).isoformat(), 'total_time': 100},
            {'date': (today - timedelta(days=1)).isoformat(), 'total_time': 150},
            {'date': today.isoformat(), 'total_time': 75}
        ]
        
        total_completed = 30
        total_focus_time = 750
    
    conn.close()
    return jsonify({
        'daily_tasks': daily_tasks, 
        'daily_time': daily_time,
        'total_completed': total_completed,
        'total_focus_time': total_focus_time
    })

@app.route('/api/dashboard-stats')
@require_session
def dashboard_stats():
    conn = sqlite3.connect('timemanager.db')
    c = conn.cursor()
    user_id = session['user_id']
    
    today = datetime.now().date().isoformat()
    
    c.execute('SELECT COUNT(*) FROM tasks WHERE user_id = ? AND DATE(created_at) = ?', (user_id, today))
    tasks_today = c.fetchone()[0]
    
    c.execute('SELECT COUNT(*) FROM tasks WHERE user_id = ? AND status = "completed" AND DATE(created_at) = ?', (user_id, today))
    completed_today = c.fetchone()[0]
    
    c.execute('SELECT COUNT(*) FROM tasks WHERE user_id = ? AND status = "pending"', (user_id,))
    pending_tasks = c.fetchone()[0]
    
    c.execute('SELECT SUM(duration) FROM pomodoro_sessions WHERE user_id = ? AND DATE(start_time) = ?', (user_id, today))
    focus_time = c.fetchone()[0] or 0
    
    # Return sample data if no data exists
    if tasks_today == 0 and pending_tasks == 0:
        tasks_today = 5
        completed_today = 2
        pending_tasks = 3
        focus_time = 75
    
    conn.close()
    return jsonify({
        'tasks_today': tasks_today,
        'completed_today': completed_today,
        'pending_tasks': pending_tasks,
        'focus_time_today': focus_time
    })

@app.route('/api/goals', methods=['GET', 'POST'])
@require_session
def goals():
    conn = sqlite3.connect('timemanager.db')
    c = conn.cursor()
    user_id = session['user_id']
    
    if request.method == 'POST':
        data = request.json
        c.execute('''INSERT INTO goals (user_id, title, description, target_value, deadline, category)
                     VALUES (?, ?, ?, ?, ?, ?)''',
                  (user_id, data['title'], data.get('description', ''), data['target_value'], 
                   data.get('deadline'), data.get('category', 'personal')))
        conn.commit()
        goal_id = c.lastrowid
        conn.close()
        return jsonify({'id': goal_id, 'status': 'created'})
    
    c.execute('SELECT * FROM goals WHERE user_id = ? ORDER BY deadline ASC', (user_id,))
    goals = [dict(zip([col[0] for col in c.description], row)) for row in c.fetchall()]
    conn.close()
    return jsonify(goals)

@app.route('/api/goals/<int:goal_id>/progress', methods=['PUT'])
@require_session
def update_goal_progress(goal_id):
    data = request.json
    conn = sqlite3.connect('timemanager.db')
    c = conn.cursor()
    user_id = session['user_id']
    
    c.execute('UPDATE goals SET current_value = ? WHERE id = ? AND user_id = ?', 
              (data['current_value'], goal_id, user_id))
    conn.commit()
    conn.close()
    return jsonify({'status': 'updated'})

@app.route('/api/pomodoro/incomplete', methods=['POST'])
@require_session
def log_incomplete_session():
    data = request.json
    conn = sqlite3.connect('timemanager.db')
    c = conn.cursor()
    user_id = session['user_id']
    
    actual_duration = data['actual_duration']
    
    c.execute('''INSERT INTO pomodoro_sessions (user_id, task_id, duration, start_time, completed, session_type)
                 VALUES (?, ?, ?, ?, ?, ?)''',
              (user_id, data.get('task_id'), actual_duration, data['start_time'], 
               False, data.get('session_type', 'work')))
    conn.commit()
    conn.close()
    return jsonify({'status': 'incomplete_session_logged'})

@app.route('/api/task-completion-analytics')
@require_session
def task_completion_analytics():
    conn = sqlite3.connect('timemanager.db')
    c = conn.cursor()
    user_id = session['user_id']
    
    # Tasks completed with timers vs manual completion
    c.execute('''SELECT 
                    COUNT(CASE WHEN p.session_type = 'manual_complete' THEN 1 END) as manual_completions,
                    COUNT(CASE WHEN p.session_type != 'manual_complete' THEN 1 END) as timer_completions
                 FROM tasks t 
                 LEFT JOIN pomodoro_sessions p ON t.id = p.task_id 
                 WHERE t.user_id = ? AND t.status = 'completed' ''', (user_id,))
    
    completion_stats = c.fetchone()
    
    # Average completion time by category
    c.execute('''SELECT t.category, AVG(p.duration) as avg_time
                 FROM tasks t 
                 JOIN pomodoro_sessions p ON t.id = p.task_id 
                 WHERE t.user_id = ? AND p.completed = 1
                 GROUP BY t.category''', (user_id,))
    
    category_times = [dict(zip([col[0] for col in c.description], row)) for row in c.fetchall()]
    
    conn.close()
    return jsonify({
        'manual_completions': completion_stats[0] or 0,
        'timer_completions': completion_stats[1] or 0,
        'category_times': category_times
    })

if __name__ == '__main__':
    init_db()
    app.run(debug=True)