class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;

        if (size[rootX] > size[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        } else {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        }
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int totalCells = n * n;
        DSU dsu(totalCells);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int idx = i * n + j;
                    for (auto& dir : directions) {
                        int i_ = i + dir[0];
                        int j_ = j + dir[1];
                        int idx_ = i_ * n + j_;
                        if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < n && grid[i_][j_] == 1) {
                            dsu.Union(idx, idx_);
                        }
                    }
                }
            }
        }

        for (int idx = 0; idx < totalCells; idx++) {
            if (grid[idx / n][idx % n] == 1) {
                maxArea = max(maxArea, dsu.getSize(idx));
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> uniqueParents;
                    for (auto& dir : directions) {
                        int i_   = i + dir[0];
                        int j_   = j + dir[1];
                        int idx_ = i_ * n + j_;
                        if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < n && grid[i_][j_] == 1) {
                            uniqueParents.insert(dsu.find(idx_));
                        }
                    }

                    int newSize = 1;
                    for (int parent : uniqueParents) {
                        newSize += dsu.getSize(parent);
                    }
                    maxArea = max(maxArea, newSize);
                }
            }
        }

        return maxArea;
    }
};