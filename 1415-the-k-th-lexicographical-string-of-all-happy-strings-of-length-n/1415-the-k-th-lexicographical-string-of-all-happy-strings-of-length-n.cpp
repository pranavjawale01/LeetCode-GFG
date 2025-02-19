class Solution {
public:
    vector<string> ans;

    void solve(int n, string &curr) {
        if (curr.size() == n) {
            ans.push_back(curr);
            return;
        }
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!curr.empty() && curr.back() == ch) continue;
            curr.push_back(ch);
            solve(n, curr);
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        solve(n, curr);
        return ans.size() < k ? "" : ans[k-1];
    }
};