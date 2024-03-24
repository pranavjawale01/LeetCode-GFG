class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                return abs(nums[i]);
            }
            nums[index] *= -1; 
        }
        return -1;
    }
};

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         for (int &num : nums) {
//             if (mp[num] == 0) {
//                 mp[num]++;
//             } else {
//                 return num;
//             }
//         }
//         return -1;
//     }
// };