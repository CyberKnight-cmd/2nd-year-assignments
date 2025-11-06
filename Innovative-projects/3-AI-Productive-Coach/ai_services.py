import sqlite3
from datetime import datetime, timedelta
import re
import json
import statistics

class SimpleLinearRegression:
    def __init__(self):
        self.slope = 0
        self.intercept = 0
        self.is_trained = False
    
    def fit(self, X, y):
        if len(X) < 2:
            return
        n = len(X)
        sum_x = sum(X)
        sum_y = sum(y)
        sum_xy = sum(X[i] * y[i] for i in range(n))
        sum_x2 = sum(x * x for x in X)
        
        self.slope = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x)
        self.intercept = (sum_y - self.slope * sum_x) / n
        self.is_trained = True
    
    def predict(self, X):
        if not self.is_trained:
            return [25] * len(X)
        return [self.slope * x + self.intercept for x in X]

class TimeEstimator:
    def __init__(self, db_path='timemanager.db'):
        self.db_path = db_path
        self.model = SimpleLinearRegression()
        self.is_trained = False
    
    def train_model(self, user_id):
        conn = sqlite3.connect(self.db_path)
        c = conn.cursor()
        
        query = '''
        SELECT t.title, t.estimated_time, p.duration, t.category, t.priority
        FROM tasks t 
        JOIN pomodoro_sessions p ON t.id = p.task_id 
        WHERE t.user_id = ? AND p.completed = 1
        '''
        c.execute(query, (user_id,))
        data = c.fetchall()
        conn.close()
        
        if len(data) < 3:
            return False
        
        # Simple feature: word count
        X = [len(row[0].split()) for row in data]
        y = [row[2] for row in data]
        
        self.model.fit(X, y)
        self.is_trained = True
        return True
    
    def estimate_time(self, title, category='work', priority=2):
        if not self.is_trained:
            # Rule-based fallback
            word_count = len(title.split())
            base_time = word_count * 5 + priority * 10
            return max(5, min(120, base_time))
        
        word_count = len(title.split())
        estimate = self.model.predict([word_count])[0]
        return max(5, min(120, int(estimate)))

class ProductivityAnalyzer:
    def __init__(self, db_path='timemanager.db'):
        self.db_path = db_path
    
    def analyze_peak_hours(self, user_id):
        conn = sqlite3.connect(self.db_path)
        c = conn.cursor()
        
        query = '''
        SELECT strftime('%H', start_time) as hour, AVG(duration) as avg_duration, COUNT(*) as session_count
        FROM pomodoro_sessions 
        WHERE user_id = ? AND completed = 1 AND start_time IS NOT NULL
        GROUP BY hour
        ORDER BY avg_duration DESC
        '''
        c.execute(query, (user_id,))
        data = c.fetchall()
        conn.close()
        
        if not data:
            return {'peak_hour': 9, 'productivity_score': 0, 'recommendations': ['Complete some tasks to get AI insights!']}
        
        peak_hour = int(data[0][0]) if data[0][0] else 9
        avg_productivity = statistics.mean([row[1] for row in data if row[1]])
        
        recommendations = []
        if peak_hour < 12:
            recommendations.append("You're most productive in the morning. Schedule important tasks before noon.")
        elif peak_hour > 18:
            recommendations.append("You're a night owl! Consider tackling complex tasks in the evening.")
        else:
            recommendations.append("Your peak productivity is in the afternoon. Plan accordingly.")
        
        return {
            'peak_hour': peak_hour,
            'productivity_score': round(avg_productivity, 1),
            'recommendations': recommendations
        }
    
    def get_completion_patterns(self, user_id):
        conn = sqlite3.connect(self.db_path)
        c = conn.cursor()
        
        query = '''
        SELECT DATE(created_at) as date, 
               COUNT(*) as total_tasks,
               SUM(CASE WHEN status = 'completed' THEN 1 ELSE 0 END) as completed_tasks
        FROM tasks 
        WHERE user_id = ? 
        GROUP BY DATE(created_at)
        ORDER BY date DESC LIMIT 7
        '''
        c.execute(query, (user_id,))
        data = c.fetchall()
        conn.close()
        
        if not data:
            return {'completion_rate': 0, 'trend': 'stable'}
        
        completion_rates = []
        for row in data:
            if row[1] > 0:
                completion_rates.append((row[2] / row[1]) * 100)
        
        if not completion_rates:
            return {'completion_rate': 0, 'trend': 'stable'}
        
        avg_rate = statistics.mean(completion_rates)
        
        # Simple trend analysis
        if len(completion_rates) >= 3:
            recent_avg = statistics.mean(completion_rates[:3])
            older_avg = statistics.mean(completion_rates[-3:])
            if recent_avg > older_avg + 10:
                trend = 'improving'
            elif recent_avg < older_avg - 10:
                trend = 'declining'
            else:
                trend = 'stable'
        else:
            trend = 'stable'
        
        return {
            'completion_rate': round(avg_rate, 1),
            'trend': trend
        }

class NLPTaskParser:
    def __init__(self):
        self.priority_keywords = {
            'high': ['urgent', 'important', 'critical', 'asap', 'priority', 'high'],
            'medium': ['medium', 'normal', 'regular'],
            'low': ['low', 'later', 'when possible', 'eventually']
        }
        
        self.time_patterns = [
            (r'(\d+)\s*hours?', lambda x: int(x) * 60),
            (r'(\d+)\s*mins?', lambda x: int(x)),
            (r'(\d+)\s*minutes?', lambda x: int(x)),
            (r'(\d+)h', lambda x: int(x) * 60),
            (r'(\d+)m', lambda x: int(x))
        ]
        
        self.deadline_patterns = [
            r'by\s+(\w+)',
            r'due\s+(\w+)',
            r'deadline\s+(\w+)',
            r'finish\s+by\s+(\w+)'
        ]
    
    def parse_task(self, text):
        text_lower = text.lower()
        
        # Extract priority
        priority = 2
        for level, keywords in self.priority_keywords.items():
            if any(keyword in text_lower for keyword in keywords):
                priority = {'high': 3, 'medium': 2, 'low': 1}[level]
                break
        
        # Extract time estimation
        estimated_time = 25
        for pattern, converter in self.time_patterns:
            match = re.search(pattern, text_lower)
            if match:
                estimated_time = converter(match.group(1))
                break
        
        # Extract deadline
        deadline = None
        for pattern in self.deadline_patterns:
            match = re.search(pattern, text_lower)
            if match:
                day_word = match.group(1)
                if day_word in ['today', 'tomorrow', 'friday', 'monday', 'tuesday', 'wednesday', 'thursday', 'saturday', 'sunday']:
                    deadline = day_word
                break
        
        # Clean title
        title = text
        for pattern, _ in self.time_patterns:
            title = re.sub(pattern, '', title, flags=re.IGNORECASE)
        
        for keywords in self.priority_keywords.values():
            for keyword in keywords:
                title = re.sub(r'\b' + keyword + r'\b', '', title, flags=re.IGNORECASE)
        
        title = re.sub(r'\s+', ' ', title).strip()
        
        return {
            'title': title,
            'priority': priority,
            'estimated_time': estimated_time,
            'deadline': deadline,
            'category': 'work'
        }

class AICoach:
    def __init__(self, db_path='timemanager.db'):
        self.time_estimator = TimeEstimator(db_path)
        self.productivity_analyzer = ProductivityAnalyzer(db_path)
        self.nlp_parser = NLPTaskParser()
    
    def initialize_for_user(self, user_id):
        return self.time_estimator.train_model(user_id)
    
    def get_smart_estimate(self, title, category='work', priority=2):
        return self.time_estimator.estimate_time(title, category, priority)
    
    def get_productivity_insights(self, user_id):
        peak_analysis = self.productivity_analyzer.analyze_peak_hours(user_id)
        completion_patterns = self.productivity_analyzer.get_completion_patterns(user_id)
        
        return {
            'peak_hours': peak_analysis,
            'completion_patterns': completion_patterns,
            'insights': self._generate_insights(peak_analysis, completion_patterns)
        }
    
    def parse_natural_language_task(self, text):
        return self.nlp_parser.parse_task(text)
    
    def _generate_insights(self, peak_analysis, completion_patterns):
        insights = []
        
        if completion_patterns['completion_rate'] > 80:
            insights.append("Excellent! You're completing most of your tasks.")
        elif completion_patterns['completion_rate'] < 50:
            insights.append("Consider breaking large tasks into smaller chunks.")
        
        if completion_patterns['trend'] == 'improving':
            insights.append("Your productivity is trending upward!")
        elif completion_patterns['trend'] == 'declining':
            insights.append("Your completion rate is declining. Time for a productivity reset?")
        
        insights.extend(peak_analysis['recommendations'])
        
        return insights