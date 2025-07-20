class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) {
            return 0;
        }
        priority_queue<int> pq_max;
        priority_queue<int, vector<int>, greater<int>> pq_min;
        for (int num : nums) {
            pq_min.push(num);
            pq_max.push(num);
            if (pq_max.size() > 4) {
                pq_max.pop();
            }
            if (pq_min.size() > 4) {
                pq_min.pop();
            }
        }
        int l = 3, r = n - 4;
        while (!pq_max.empty()) {
            nums[l--] = pq_max.top();
            pq_max.pop();
            nums[r++] = pq_min.top();
            pq_min.pop();
        }
        return min({nums[n-1] - nums[3], nums[n-2] - nums[2], nums[n-3] - nums[1], nums[n-4] - nums[0]});
    }
};



// class Solution {
// public:
//     int minDifference(vector<int>& nums) {
//         int n = nums.size();
//         if (n <= 4) {
//             return 0;
//         }
//         sort(nums.begin(), nums.end());
//         return min({nums[n-1] - nums[3], nums[n-2] - nums[2], nums[n-3] - nums[1], nums[n-4] - nums[0]});
//     }
// };