class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<long long> pq;
        for (int &x : nums) pq.push(x);
        while (k--) {
            int x = pq.top();
            ans += (long long) x;
            pq.pop();
            pq.push((long long)ceil((double)x / 3));
        }
        return ans;
    }
};