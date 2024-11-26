class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        unordered_map<int, int> mp;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    mp[i]++;
                } else {
                    mp[j]++;
                }
            }
        }
        int team = -1;
        int freq = 0;
        for (auto &x : mp) {
            if (x.second > freq) {
                freq = x.second;
                team = x.first;
            }
        }
        return team;
    }
};