class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int x : nums) {
            if (pq.empty() || pq.top() < x) pq.push(x);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};