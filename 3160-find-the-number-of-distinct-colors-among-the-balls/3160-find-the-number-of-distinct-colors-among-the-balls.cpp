class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        unordered_map<int, int> mp;
        vector<int> arr(limit+1, -1);
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int ball = queries[i][0];
            int color = queries[i][1];
            if (arr[ball] != -1) {
                int prevColor = arr[ball];
                mp[prevColor]--;
                if (mp[prevColor] == 0) {
                    mp.erase(prevColor);
                }
            }
            arr[ball] = color;
            mp[color]++;
            res[i] = mp.size();
        }
        return res;
    }
};