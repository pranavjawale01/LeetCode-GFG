class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void DSU(int x, int y) {
        int par_x = find(x);
        int par_y = find(y);

        if (par_x != par_y) {
            if (rank[par_x] > rank[par_y]) {
                parent[par_y] = par_x;
            } else if (rank[par_x] < rank[par_y]) {
                parent[par_x] = par_y;
            } else {
                parent[par_x] = par_y;
                rank[par_y]++;
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if (edges < n - 1) {
            return -1;
        }
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int count = n;
        for (auto x : connections) {
            if (find(x[0]) != find(x[1])) {
                DSU(x[0], x[1]);
                count--;
            }
        }
        return count - 1;
    }
};