# 🤖 AI-Powered Productivity Coach

An intelligent time management application with AI-driven insights, smart task estimation, and natural language processing.

## 🚀 AI Features (Phase 1)

- 🧠 **Smart Time Estimation**: AI predicts realistic task durations based on your history
- 📝 **Natural Language Task Creation**: "Finish report by Friday, high priority, 2 hours" → structured task
- 📊 **Productivity Pattern Analysis**: AI identifies your peak performance hours
- 💡 **Intelligent Insights**: Personalized productivity recommendations
- 🎯 **Adaptive Learning**: System improves suggestions based on your behavior

## 📋 Core Features

- 🕐 **Smart Task Scheduling**: AI-enhanced priority-based organization
- ⏱️ **Pomodoro Timer**: 25-minute focus sessions with break reminders
- 📊 **Analytics Dashboard**: AI-powered productivity insights with charts
- 🎯 **Goal Tracking**: SMART goal setting and progress monitoring
- 🔔 **Task Management**: Add, complete, and delete tasks with AI assistance

## Quick Start

1. Install dependencies:
```bash
pip install -r requirements.txt
```

2. Populate sample data (optional but recommended):
```bash
python populate_data.py
```

3. Test AI features:
```bash
python test_ai.py
```

4. Run the application:
```bash
python app.py
# OR double-click START.bat
```

5. Open http://localhost:5000 in your browser

## 🤖 AI Usage Examples

### Natural Language Task Creation
```
"Review code by tomorrow, high priority, should take 45 minutes"
→ AI extracts: Title, Priority (High), Deadline (tomorrow), Time (45min)
```

### Smart Time Estimation
- AI learns from your completion history
- Suggests realistic durations based on task complexity
- Improves accuracy over time

### Productivity Insights
- "You're most productive at 10 AM - schedule important tasks then"
- "Your completion rate is trending upward! 📈"
- "Consider breaking large tasks into smaller chunks"

## Usage

- **Add Tasks**: Use natural language or traditional form
- **AI Estimation**: Click 🤖 button for smart time estimates
- **Start Pomodoro**: Use the timer for focused work sessions
- **View AI Insights**: Check personalized productivity recommendations
- **Track Progress**: Monitor AI-analyzed patterns

## Tech Stack

- **Backend**: Flask + SQLite + scikit-learn
- **AI/ML**: Linear Regression, NLP, Pattern Analysis
- **Frontend**: HTML/CSS/JS + Tailwind CSS
- **Charts**: Chart.js
- **Data Processing**: pandas, numpy

## Database Schema

- **tasks**: Task management with priorities and deadlines
- **pomodoro_sessions**: Focus session tracking
- **goals**: Goal setting and progress tracking