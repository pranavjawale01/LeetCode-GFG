class Solution {
public:
    vector<string> ans;
    void solve(int n, string s, int i) {
        if (i == n) {
            ans.push_back(s);
            return;
        }
        if (i == 0 || s[i - 1] == '1') {
            solve(n, s + '1', i + 1);
            solve(n, s + '0', i + 1);
        } else {
            solve(n, s + '1', i + 1);
        }
    }
    vector<string> validStrings(int n) {
        solve(n, "", 0);
        return ans;
    }
};