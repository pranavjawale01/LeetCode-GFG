class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        vector<int> ans;
        int i = 0, j = 0;
        int m = nums1.size(), n = nums2.size();
        while (i < m && j < n) {
            if (nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                while(i < m - 1 && nums1[i] == nums1[i+1]) {
                    i++;
                } 
                while (j < n - 1 && nums2[j] == nums2[j+1]) {
                    j++;
                }
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     bool binarySearch(vector<int>& nums, int num) {
//         int low = 0, high = nums.size() - 1;
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             if (nums[mid] == num) {
//                 return true;
//             } else if (num > nums[mid]) {
//                 low = mid + 1;
//             } else {
//                 high = mid - 1;
//             }
//         }
//         return false;
//     }
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         sort(begin(nums1), end(nums1));
//         unordered_set<int> ans;
//         for (int& num : nums2) {
//             if (binarySearch(nums1, num)) {
//                 ans.insert(num);
//             }
//         }
//         vector<int> output(begin(ans), end(ans));
//         return output;
//     }
// };

// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         unordered_set<int> s1(begin(nums1), end(nums1));
//         vector<int> ans;
//         for (int num : nums2) {
//             if (s1.find(num) != s1.end()) {
//                 ans.push_back(num);
//                 s1.erase(num);
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         unordered_set<int> s1(begin(nums1), end(nums1));
//         unordered_set<int> s2(begin(nums2), end(nums2));
//         vector<int> ans;
//         for (int num : s2) {
//             if (s1.find(num) != s1.end()) {
//                 ans.push_back(num);
//             }
//         }
//         return ans;
//     }
// };