class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] <= 2) {
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};


// class Solution {
// public:
//     void swapElements(vector<int>& nums, int start, int& n, int num) {
//         int i;
//         for (i = start; i < n - 1; i++) {
//             nums[i] = nums[i+1];
//         }
//         nums[i] = num;
//         n--;
//     }
    
//     int removeDuplicates(vector<int>& nums) {
//         int n = nums.size();
//         int count = n;
//         for (int i = 0 ; i < n - 2; i++) {
//             if (nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) {
//                 swapElements(nums,i,n,nums[i]);
//                 count--;
//                 i--;
//             }
//         }
//         return count;
//     }
// };