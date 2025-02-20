class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";
        for (int i = 0; i < n; i++) {
            char ch = nums[i][i];
            ans += (ch == '0') ? '1' : '0';
        }
        return ans;
    }
};









// class Solution {
// public:
//     unordered_set<string> st;
//     string ans = "";

//     void solve(string &curr, int n) {
//         if (curr.size() == n) {
//             if (st.find(curr) == st.end()) {
//                 ans = curr;
//             }
//             return;
//         }
//         if (!ans.empty()) return;

//         curr.push_back('0');
//         solve(curr, n);
//         curr.pop_back();

//         curr.push_back('1');
//         solve(curr, n);
//         curr.pop_back();
//     }

//     string findDifferentBinaryString(vector<string>& nums) {
//         int n = nums[0].size();
//         for (string x : nums) st.insert(x);
//         string curr = "";
//         solve(curr, n);
//         return ans;
//     }
// };