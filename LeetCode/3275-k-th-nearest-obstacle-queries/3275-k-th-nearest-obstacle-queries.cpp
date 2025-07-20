class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int n = queries.size();
        vector<int> ans;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            pq.push(abs(x) + abs(y));
            if (pq.size() > k) {
                pq.pop();
            }
            if (pq.size() == k) {
                ans.push_back(pq.top());
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};