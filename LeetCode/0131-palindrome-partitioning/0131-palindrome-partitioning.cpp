class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) {
                return false;
            }
        }
        return true;
    }

    void solve(string s, vector<string>& temp, int start) {
        if (start == s.size()) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = start; i < s.size(); i++) {
            string sub = s.substr(start, i - start + 1);
            if (isPalindrome(sub)) {
                temp.push_back(sub);
                solve(s, temp, i + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(s, temp, 0);
        return ans;
    }
};