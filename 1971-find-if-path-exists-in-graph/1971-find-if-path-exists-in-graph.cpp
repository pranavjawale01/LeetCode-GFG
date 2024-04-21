class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        sort(edges.begin(), edges.end());
        for (int i = 0; i < n - 1; i++) {
            if (edges[i][1] == destination && edges[i][0] == source) {
                return true;
            }
            if (edges[i][0] == source) {
                while (i < n - 1) {
                    if (edges[i][1] == destination && edges[i][0] == edges[i-1][1]) {
                        return true;
                    }
                    i++;
                }
                return false;
            }
        }
        return false;
    }
};