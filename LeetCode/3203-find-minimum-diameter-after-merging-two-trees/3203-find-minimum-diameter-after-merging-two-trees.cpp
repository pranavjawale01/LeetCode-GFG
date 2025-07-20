class Solution {
public:
    void findFarthest(int node, int par, int dis, unordered_map<int, vector<int>> &mp, pair<int, int> &res) {
        if (dis > res.first) {
            res = {dis, node};
        }
        for (auto &x : mp[node]) {
            if (x != par) {
                findFarthest(x, node, dis + 1, mp, res);
            }
        }
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> mp1, mp2;
        for (auto &x : edges1) {
            mp1[x[0]].push_back(x[1]);
            mp1[x[1]].push_back(x[0]);
        }
        for (auto &x : edges2) {
            mp2[x[0]].push_back(x[1]);
            mp2[x[1]].push_back(x[0]);
        }
        pair<int, int> res1 = {INT_MIN, -1}, res2 = {INT_MIN, -1};
        findFarthest(0, -1, 0, mp1, res1);
        findFarthest(res1.second, -1, 0, mp1, res2);
        int d1 = res2.first;
        res1 = {INT_MIN, -1}, res2 = {INT_MIN, -1};
        findFarthest(0, -1, 0, mp2, res1);
        findFarthest(res1.second, -1, 0, mp2, res2);
        int d2 = res2.first;
        return max({d1, d2, ((d1 + 1) / 2) + ((d2 + 1) / 2) + 1 });
    }
};