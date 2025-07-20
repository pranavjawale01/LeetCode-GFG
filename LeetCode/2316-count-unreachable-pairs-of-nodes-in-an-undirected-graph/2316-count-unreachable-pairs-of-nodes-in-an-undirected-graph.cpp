class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void DSU(int x, int y) {
        int parX = find(x);
        int parY = find(y);
        if (parX != parY) {
            if (rank[parY] > rank[parX]) {
                parent[parX] = parY;
            } else if (rank[parY] < rank[parX]) {
                parent[parY] = parX;
            } else {
                parent[parX] = parY;
                rank[parY]++;
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        rank.resize(n, 0);
        parent.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (auto &x : edges) {
            DSU(x[0], x[1]);
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int father = find(i);
            mp[father]++;
        }
        long long result = 0;
        long long remainingNodes = n;
        for (auto &x : mp) {
            long long size = x.second;
            result += (size) * (remainingNodes - size);
            remainingNodes -= size;
        }
        return result;
    }
};