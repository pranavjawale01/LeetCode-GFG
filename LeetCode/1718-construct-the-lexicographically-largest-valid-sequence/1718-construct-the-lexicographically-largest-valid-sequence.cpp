class Solution {
public:
    vector<int> ans;
    vector<bool> vis;
    bool solve(int i, int n) {
        if (i >= ans.size()) {
            return true;
        }
        if (ans[i] != -1) {
            return solve(i+1, n);
        }
        for (int num = n; num >= 1; num--) {
            if (vis[num]) continue;
            vis[num] = true;
            ans[i] = num;
            if (num == 1) {
                if (solve(i+1, n)) {
                    return true;
                }
            } else {
                int j = i + num;
                if (j < ans.size() && ans[j] == -1) {
                    ans[j] = num;
                    if (solve(i+1, n)) {
                        return true;
                    }
                    ans[j] = -1;
                }
            }
            vis[num] = false;
            ans[i] = -1;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        ans.resize(2 * n - 1, -1);
        vis.resize(n+1, false);
        solve(0, n);
        return ans;
    }
};