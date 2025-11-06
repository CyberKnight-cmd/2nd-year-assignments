# Time Management Software

A minimal yet powerful time management application with smart scheduling, Pomodoro timer, and analytics.

## Features

- 🕐 **Smart Task Scheduling**: Priority-based task organization
- 📅 **Calendar Integration**: Visual task scheduling with FullCalendar
- ⏱️ **Pomodoro Timer**: 25-minute focus sessions with break reminders
- 📊 **Analytics Dashboard**: Daily productivity tracking with charts
- 🎯 **Goal Tracking**: SMART goal setting and progress monitoring
- 🔔 **Task Management**: Add, complete, and delete tasks with priorities

## Quick Start

1. Install dependencies:
```bash
pip install -r requirements.txt
```

2. Run the application:
```bash
python app.py
```

3. Open http://localhost:5000 in your browser

## Usage

- **Add Tasks**: Click "+ Add" in the Tasks panel
- **Start Pomodoro**: Use the timer for focused work sessions
- **View Analytics**: Check daily productivity charts
- **Set Goals**: Add SMART goals with target values
- **Calendar View**: See tasks in calendar format

## Tech Stack

- **Backend**: Flask + SQLite
- **Frontend**: HTML/CSS/JS + Bootstrap
- **Charts**: Chart.js
- **Calendar**: FullCalendar.js

## Database Schema

- **tasks**: Task management with priorities and deadlines
- **pomodoro_sessions**: Focus session tracking
- **goals**: Goal setting and progress tracking