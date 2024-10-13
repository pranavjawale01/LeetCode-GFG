class Solution {
public:
    int solve(unordered_map<int, int> &mp, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto &y : mp) {
            pq.push({y.second, y.first});
            if (pq.size() > x) {
                pq.pop();
            }
        }
        int sum = 0;
        while (!pq.empty()) {
            sum += pq.top().first * pq.top().second;
            pq.pop();
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;
        }
        vector<int> ans(n - k + 1);
        ans[0] = solve(mp, x);
        for (int i = k; i < n; i++) {
            mp[nums[i - k]]--;
            if (mp[nums[i - k]] == 0) {
                mp.erase(nums[i - k]);
            }
            mp[nums[i]]++;
            ans[i - k + 1] = solve(mp, x);
        }
        return ans;
    }
};











// class Solution {
// public:
//     vector<int> findXSum(vector<int>& nums, int k, int x) {
//         int n = nums.size();
//         vector<int> ans;
//         auto cmp = [](pair<int, int> &a, pair<int, int> &b){
//             if (a.first == b.first) {
//                 return a.second > b.second;
//             }
//             return a.first > b.first;
//         };
//         for (int i = 0; i <= n - k; i++) {
//             unordered_map<int, int> mp;
//             for (int j = i; j < i + k; j++) {
//                 mp[nums[j]]++;
//             }
//             vector<pair<int, int>> vec;
//             for (auto &y : mp) {
//                 vec.push_back({y.second, y.first});
//             }
//             sort(vec.begin(), vec.end(), cmp);
//             int sum = 0;
//             int temp = 0;
//             for (auto &y : vec) {
//                 if (temp >= x) {
//                     break;
//                 }
//                 sum += y.second * y.first;
//                 temp++;
//             }
//             ans.push_back(sum);
//         }
//         return ans;
//     }
// };