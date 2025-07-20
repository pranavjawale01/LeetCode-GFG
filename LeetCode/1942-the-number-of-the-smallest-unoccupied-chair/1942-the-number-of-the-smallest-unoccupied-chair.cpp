class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> order(n);
        for (int i = 0; i < n; i++) order[i] = i;
        
        auto cmp = [&times](int a, int b) {
            return times[a][0] < times[b][0];
        };
        
        sort(order.begin(), order.end(), cmp);
        
        priority_queue<int, vector<int>, greater<int>> hpq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> lpq;
        
        for (int i = 0; i < n; i++) hpq.push(i);
        
        for (int i : order) {
            int arrival = times[i][0], leave = times[i][1];
            
            while (!lpq.empty() && lpq.top().first <= arrival) {
                hpq.push(lpq.top().second);
                lpq.pop();
            }
            
            int seat = hpq.top();
            hpq.pop();
            
            if (i == targetFriend) return seat;
            
            lpq.push({leave, seat});
        }
        return -1;
    }
};