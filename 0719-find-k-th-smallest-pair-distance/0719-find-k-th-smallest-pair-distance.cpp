class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int maxEl = *max_element(nums.begin(), nums.end());
        vector<int> vec(maxEl+1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                vec[abs(nums[i] - nums[j])]++;
            }
        }
        for (int d = 0; d < maxEl + 1; d++) {
            k -= vec[d];
            if (k <= 0) {
                return d;
            }
        }
        return -1;
    }
};








// TLE
// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> pq;

//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 pq.push_back(abs(nums[j] - nums[i]));
//             }
//         }

//         sort(pq.begin(), pq.end());
 
//         return pq[k-1];
//     }
// };









// TLE
// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         int n = nums.size();
//         priority_queue<int, vector<int>, greater<int>> pq;

//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 pq.push(abs(nums[j] - nums[i]));
//             }
//         }

//         while (k > 1) {
//             pq.pop();
//             k--;
//         }
 
//         return pq.top();
//     }
// };