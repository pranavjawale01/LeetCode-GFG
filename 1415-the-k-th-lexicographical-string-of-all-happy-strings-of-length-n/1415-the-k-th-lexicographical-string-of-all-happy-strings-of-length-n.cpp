class Solution {
public:
    string ans = "";
    void solve(int n, int &k, string &curr) {
        if (curr.size() == n) {
            k--;
            if (k == 0) {
                ans = curr;
                return;
            }
            return;
        }
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!curr.empty() && curr.back() == ch) {
                continue;
            }
            curr.push_back(ch);
            solve(n, k, curr);
            if (ans.size()) return;
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        solve(n, k, curr);
        return ans;
    }
};









// class Solution {
// public:
//     vector<string> ans;

//     void solve(int n, string &curr) {
//         if (curr.size() == n) {
//             ans.push_back(curr);
//             return;
//         }
//         for (char ch = 'a'; ch <= 'c'; ch++) {
//             if (!curr.empty() && curr.back() == ch) continue;
//             curr.push_back(ch);
//             solve(n, curr);
//             curr.pop_back();
//         }
//     }

//     string getHappyString(int n, int k) {
//         string curr = "";
//         solve(n, curr);
//         return ans.size() < k ? "" : ans[k-1];
//     }
// };