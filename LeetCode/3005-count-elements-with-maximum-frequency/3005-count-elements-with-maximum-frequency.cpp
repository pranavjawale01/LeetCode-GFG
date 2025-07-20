class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> vec(101, 0);
        int maxCount = 0, ans = 0;
        for (int num : nums) {
            vec[num]++;
            if (vec[num] == maxCount) {
                ans += vec[num];
            }
            if (vec[num] > maxCount) {
                maxCount = vec[num];
                ans = vec[num];
            }
        }
        return ans;
    }
};
// class Solution {
// public:
//     int maxFrequencyElements(vector<int>& nums) {
//         unordered_map<int , int> mp;
//         int maxCount = 0, ans = 0;
//         for (int num : nums) {
//             mp[num]++;
//             maxCount = max(maxCount, mp[num]);
//         }
//         for (auto x : mp) {
//             if (x.second == maxCount) {
//                 ans += x.second;
//             }
//         }
//         return ans;
//     }
// };