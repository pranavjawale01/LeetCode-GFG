class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int, map<int, int>> mp;
        
        for (auto p : pick) {
            int x = p[0];
            int y = p[1];
            mp[x][y]++;
        }
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            int require = i + 1;
            bool flag = false;
            for (auto x : mp[i]) {
                if (x.second >= require) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                ans++;
            }
        }
        
        return ans;
    }
};