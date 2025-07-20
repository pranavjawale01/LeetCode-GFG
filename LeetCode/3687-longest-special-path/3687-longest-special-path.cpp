class Solution {
public:
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto x : edges) {
            int u = x[0], v = x[1], w = x[2];
            mp[u].push_back({v, w});
            mp[v].push_back({u, w});
        }
        unordered_map<int, int> depthmp;
        vector<int> path;
        int maxLength = 0, minNodes = INT_MAX;
        function<void(int, int, int, int, int)> dfs = [&](int node, int parent, int pathSum, int start, int end) {
            int prevDepth = depthmp.count(nums[node]) ? depthmp[nums[node]] : -1;
            while (start <= prevDepth) {
                pathSum -= path[start++];
            }
            if (pathSum > maxLength) {
                maxLength = pathSum;
                minNodes = end - start + 1;
            } else if (pathSum == maxLength) {
                minNodes = min(minNodes, end - start + 1);
            }
            depthmp[nums[node]] = end;
            for (auto &[nei, weight] : mp[node]) {
                if (nei != parent) {
                    path.push_back(weight);
                    dfs(nei, node, pathSum + weight, start, end + 1);
                    path.pop_back();
                }
            }
            depthmp[nums[node]] = prevDepth;
        };
        dfs(0, -1, 0, 0, 0);
        return {maxLength, minNodes};
    }
};