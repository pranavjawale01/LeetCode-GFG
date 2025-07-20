class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<>> pq;
        for (int x : nums) {
            pq.push(x);
        }
        int count = 0;
        while (pq.size() >= 2 && pq.top() < k) {
            long a = pq.top();
            pq.pop();
            long b = pq.top();
            pq.pop();
            pq.push(min(a, b) * 2 + max(a, b));
            count++;
        }
        return count;
    }
};