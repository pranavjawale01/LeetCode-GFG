class Solution {
public:
    double calGain(int pass, int total) {
        return (double)(pass + 1) / (total + 1) - (double) pass / total;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> maxpq;
        for (auto x : classes) {
            maxpq.push({calGain(x[0], x[1]), {x[0], x[1]}});
        }
        while (extraStudents--) {
            auto topEl = maxpq.top();
            maxpq.pop();
            int pass = topEl.second.first;
            int total = topEl.second.second;
            maxpq.push({calGain(pass+1, total+1), {pass+1, total+1}});
        }
        double ans = 0;
        while (!maxpq.empty()) {
            auto topEl = maxpq.top();
            maxpq.pop();
            ans += (double) topEl.second.first / topEl.second.second;
        }
        return ans / classes.size();
    }
};