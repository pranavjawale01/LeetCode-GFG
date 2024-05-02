class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int arr[2001] = {0};
        int result = -1;
        for (int &num : nums) {
            if (arr[-num + 1000] == 1) {
                result = max(result, abs(num));
            }
            arr[num + 1000] = 1;
        }
        return result;
    }
};



// class Solution {
// public:
//     int findMaxK(vector<int>& nums) {
//         unordered_set<int> st(nums.begin(), nums.end());
//         int ans = -1;
//         int n = nums.size();
//         for (int num : nums) {
//             if (st.find(-num) != st.end()) {
//                 ans = max(ans, abs(num));
//             }
//         }
//         return ans != -1 ? ans : -1;
//     }
// };




// class Solution {
// public:
//     int findMaxK(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int low = 0, high = nums.size() - 1;
//         while (low <= high) {
//             if ((nums[low] * (-1)) == nums[high]) {
//                 return nums[high];
//             } else if ((nums[low] * (-1)) < nums[high]) {
//                 high--;
//             } else if ((nums[low] * (-1)) > nums[high]) {
//                 low++;
//             }
//         }
//         return -1;
//     }
// };