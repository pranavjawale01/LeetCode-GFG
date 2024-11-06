class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int x : nums) pq.push(x);
        int n = k - 1;
        while (n--) {
            pq.pop();
        }
        return pq.top();
    }
};