class Solution {
public:
    #define p pair<int, int>
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        priority_queue<p, vector<p>, greater<p>> minpq;
        priority_queue<p> maxpq;
        int i = 0, j = 0;
        long long count = 0;
        while (j < n) {
            minpq.push({nums[j], j});
            maxpq.push({nums[j], j});
            while (abs(maxpq.top().first - minpq.top().first) > 2) {
                i++;
                while (!maxpq.empty() && maxpq.top().second < i) {
                    maxpq.pop();
                }
                while (!minpq.empty() && minpq.top().second < i) {
                    minpq.pop();
                }
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }
};









// class Solution {
// public:
//     long long continuousSubarrays(vector<int>& nums) {
//         int n = nums.size();
//         map<int, int> mp;
//         int i = 0, j = 0;
//         long long count = 0;
//         while (j < n) {
//             mp[nums[j]]++;
//             while (abs(mp.rbegin()->first - mp.begin()->first) > 2) {
//                 mp[nums[i]] -= 1;
//                 if (mp[nums[i]] == 0) {
//                     mp.erase(nums[i]);
//                 }
//                 i++;
//             }
//             count += j - i + 1;
//             j++;
//         }
//         return count;
//     }
// };