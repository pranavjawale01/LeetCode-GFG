class Solution {
public:
    #define p pair<int, int>
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> mp;
        for (auto &x : edges) {
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }
        vector<int> min1(n+1, INT_MAX), min2(n+1, INT_MAX);

        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, 1});
        min1[1] = 0;
        while (!pq.empty()) {
            auto [timePassed, node] = pq.top();
            pq.pop();
            if (node == n && min2[n] != INT_MAX) {
                return min2[n];
            }
            int div = timePassed / change;
            if (div % 2 == 1) {
                timePassed = change * (div + 1);
            }
            for (auto &nbr : mp[node]) {
                if (min1[nbr] > timePassed + time) {
                    min2[nbr] = min1[nbr];
                    min1[nbr] = timePassed + time;
                    pq.push({timePassed + time, nbr});
                } else if (min2[nbr] > timePassed + time && min1[nbr] != timePassed + time) {
                    min2[nbr] = timePassed + time;
                    pq.push({timePassed + time, nbr});
                }
            }
        }
        return -1;
    }
};