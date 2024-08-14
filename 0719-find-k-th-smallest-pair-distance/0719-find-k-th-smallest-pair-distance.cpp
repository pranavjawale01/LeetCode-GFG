class Solution {
public:
    int slidingWindowCount(vector<int>& nums, int d) {
        int i = 0, j = 0;
        int n = nums.size();
        int pairCount = 0;
        
        while (j < n) {
            while (j < n && nums[j] - nums[i] > d) {
                i++;
            }
            pairCount += (j - i);
            j++;
        }
        
        return pairCount;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums[n-1] - nums[0];
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int countPair = slidingWindowCount(nums, mid);
            
            if (countPair < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return l;
    }
};






// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> vec(n * (n - 1) / 2);
//         int idx = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 int d = abs(nums[i] - nums[j]);
//                 vec[idx] = d;
//                 idx++;
//             }
//         }

//         nth_element(vec.begin(), vec.begin() + (k - 1), vec.end());

//         return vec[k - 1];
//     }
// };






// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         int n = nums.size();
//         int maxEl = *max_element(nums.begin(), nums.end());
//         vector<int> vec(maxEl+1, 0);
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 vec[abs(nums[i] - nums[j])]++;
//             }
//         }
//         for (int d = 0; d < maxEl + 1; d++) {
//             k -= vec[d];
//             if (k <= 0) {
//                 return d;
//             }
//         }
//         return -1;
//     }
// };








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