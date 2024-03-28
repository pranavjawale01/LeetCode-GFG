class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int i = 0, j = 0, len = 0, n = nums.size();
        int culprit = 0;
        while (j < n) {
            mp[nums[j]]++;
            if (mp[nums[j]] == k + 1) {
                culprit++;
            }   
            if (culprit > 0) {
                mp[nums[i]]--;
                if (mp[nums[i]] == k) {
                    culprit--;
                }
                i++;
            } 
            if (culprit == 0) {
                len = max(len , j - i + 1);        
            }
            j++;
        }
        return len;
    }
};

// class Solution {
// public:
//     int maxSubarrayLength(vector<int>& nums, int k) {
//         unordered_map<int, int> mp;
//         int i = 0, j = 0, len = 0, n = nums.size();
//         while (j < n) {
//             mp[nums[j]]++;
//             while (i < j && mp[nums[j]] > k) {
//                 mp[nums[i]]--;
//                 i++;
//             }    
//             len = max(len , j - i + 1);        
//             j++;
//         }
//         return len;
//     }
// };