typedef pair<long, int> pi;
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        while (k--) {
            auto top = pq.top();
            pq.pop();
            int val = top.first * multiplier;
            int idx = top.second;
            pq.push({val, idx});
        }
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int val = top.first;
            int idx = top.second;
            nums[idx] = val;
        }
        return nums;
    }
};




// class Solution {
// public:
//     vector<int> getFinalState(vector<int>& nums, int k, int mult) {
//         for (int i = 0; i < k; ++i) 
//         {
//             auto min_elem = min_element(nums.begin(), nums.end());
//             *min_elem *= mult;
//         }
//         return nums;
//     }
// };