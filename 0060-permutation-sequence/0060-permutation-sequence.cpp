class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> nums;
        for (int i = 1; i < n; i++) {
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string ans = "";
        k--;
        while (true) {
            ans += to_string(nums[k / fact]);
            nums.erase(nums.begin() + k / fact);
            if (nums.empty()) break;
            k = k % fact;
            fact /= nums.size();
        }
        return ans;
    }
};









// TLE
// class Solution {
// public:
//     void solve(string &s, int idx, vector<string> &res) {
//         if (idx == s.size()) {
//             res.push_back(s);
//             return;
//         }
//         for (int i = idx; i < s.size(); i++) {
//             swap(s[i], s[idx]);
//             solve(s, idx + 1, res);
//             swap(s[i], s[idx]);
//         }
//     }
//     string getPermutation(int n, int k) {
//         string ans;
//         vector<string> res;
//         for (int i = 1; i <= n; i++) {
//             ans.push_back(i + '0');
//         }
//         solve(ans, 0, res);
//         sort(res.begin(), res.end());
//         auto it = res.begin() + (k - 1);
//         return *it;
//     }
// };