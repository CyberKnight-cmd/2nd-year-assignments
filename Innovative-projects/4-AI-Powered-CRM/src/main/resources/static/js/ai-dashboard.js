// AI Dashboard JavaScript
class AIDashboard {
    constructor() {
        this.initializeCharts();
        this.loadAIInsights();
        this.setupRealTimeUpdates();
    }

    initializeCharts() {
        // Sentiment Chart
        const sentimentCtx = document.getElementById('sentimentChart');
        if (sentimentCtx) {
            new Chart(sentimentCtx, {
                type: 'doughnut',
                data: {
                    labels: ['Positive', 'Neutral', 'Negative'],
                    datasets: [{
                        data: [60, 30, 10],
                        backgroundColor: ['#10B981', '#F59E0B', '#EF4444']
                    }]
                },
                options: {
                    responsive: true,
                    plugins: {
                        legend: { position: 'bottom' }
                    }
                }
            });
        }

        // Conversion Probability Chart
        const conversionCtx = document.getElementById('conversionChart');
        if (conversionCtx) {
            new Chart(conversionCtx, {
                type: 'line',
                data: {
                    labels: ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun'],
                    datasets: [{
                        label: 'Conversion Probability',
                        data: [65, 70, 75, 80, 85, 90],
                        borderColor: '#8B5CF6',
                        backgroundColor: 'rgba(139, 92, 246, 0.1)',
                        fill: true
                    }]
                },
                options: {
                    responsive: true,
                    scales: {
                        y: { beginAtZero: true, max: 100 }
                    }
                }
            });
        }
    }

    loadAIInsights() {
        // Load AI recommendations
        this.loadRecommendations();
        // Load sentiment analysis
        this.loadSentimentData();
        // Load predictive metrics
        this.loadPredictiveMetrics();
    }

    loadRecommendations() {
        const customerId = this.getCustomerId();
        if (customerId) {
            fetch(`/api/ai/recommendations/${customerId}`)
                .then(response => response.json())
                .then(data => this.displayRecommendations(data))
                .catch(error => console.error('Error loading recommendations:', error));
        }
    }

    loadSentimentData() {
        const customerId = this.getCustomerId();
        if (customerId) {
            fetch(`/api/ai/sentiment/${customerId}`)
                .then(response => response.json())
                .then(data => this.displaySentimentData(data))
                .catch(error => console.error('Error loading sentiment data:', error));
        }
    }

    loadPredictiveMetrics() {
        const customerId = this.getCustomerId();
        if (customerId) {
            fetch(`/api/ai/conversion-probability/${customerId}`)
                .then(response => response.json())
                .then(data => this.displayPredictiveMetrics(data))
                .catch(error => console.error('Error loading predictive metrics:', error));
        }
    }

    displayRecommendations(recommendations) {
        const container = document.getElementById('ai-recommendations');
        if (container && recommendations.length > 0) {
            container.innerHTML = recommendations.map(rec => `
                <div class="bg-white/10 backdrop-blur-sm rounded-lg p-3 mb-3">
                    <div class="flex items-center justify-between mb-2">
                        <span class="text-xs font-medium opacity-75">${rec.type}</span>
                        <span class="text-xs bg-white/20 px-2 py-1 rounded-full">${Math.round(rec.confidence * 100)}%</span>
                    </div>
                    <p class="text-sm">${rec.recommendation}</p>
                </div>
            `).join('');
        }
    }

    displaySentimentData(sentimentData) {
        const indicator = document.getElementById('sentiment-indicator');
        if (indicator && sentimentData.length > 0) {
            const avgSentiment = sentimentData.reduce((sum, item) => sum + item.sentimentScore, 0) / sentimentData.length;
            this.updateSentimentIndicator(avgSentiment);
        }
    }

    displayPredictiveMetrics(data) {
        const probabilityElement = document.getElementById('conversion-probability');
        if (probabilityElement && data.probability) {
            probabilityElement.textContent = `${Math.round(data.probability * 100)}%`;
            this.updateProgressBar('conversion-progress', data.probability * 100);
        }
    }

    updateSentimentIndicator(sentiment) {
        const indicator = document.getElementById('sentiment-indicator');
        if (indicator) {
            let icon, color;
            if (sentiment > 0.3) {
                icon = 'fas fa-smile';
                color = 'text-green-500';
            } else if (sentiment > -0.3) {
                icon = 'fas fa-meh';
                color = 'text-yellow-500';
            } else {
                icon = 'fas fa-frown';
                color = 'text-red-500';
            }
            indicator.innerHTML = `<i class="${icon} ${color}"></i>`;
        }
    }

    updateProgressBar(id, percentage) {
        const progressBar = document.getElementById(id);
        if (progressBar) {
            progressBar.style.width = `${percentage}%`;
        }
    }

    setupRealTimeUpdates() {
        // Update AI insights every 30 seconds
        setInterval(() => {
            this.loadAIInsights();
        }, 30000);
    }

    getCustomerId() {
        const path = window.location.pathname;
        const matches = path.match(/\/customers\/(\d+)/);
        return matches ? matches[1] : null;
    }
}

// Initialize AI Dashboard when DOM is loaded
document.addEventListener('DOMContentLoaded', () => {
    new AIDashboard();
});

// Utility functions for AI features
function generateAIRecommendation(customerId) {
    fetch(`/api/ai/insights/${customerId}`, { method: 'GET' })
        .then(response => response.json())
        .then(data => {
            showNotification('AI insights generated successfully', 'success');
            setTimeout(() => location.reload(), 1000);
        })
        .catch(error => {
            showNotification('Error generating AI insights', 'error');
            console.error('Error:', error);
        });
}

function showNotification(message, type) {
    const notification = document.createElement('div');
    notification.className = `fixed top-4 right-4 p-4 rounded-lg text-white z-50 ${
        type === 'success' ? 'bg-green-500' : 'bg-red-500'
    }`;
    notification.textContent = message;
    document.body.appendChild(notification);
    
    setTimeout(() => {
        notification.remove();
    }, 3000);
}