class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int m, n;

    void solve(vector<vector<int>>& image, int i, int j, int curr, int color) {
        if (i < 0 || j < 0 || i >= m || j >= n || image[i][j] != curr) {
            return;
        }
        image[i][j] = color;
        for (auto &d : dirs) {
            solve(image, i + d[0], j + d[1], curr, color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size(), n = image.size();
        int curr = image[sr][sc];
        if (curr == color) {
            return image;
        }
        solve(image, sr, sc, curr, color);
        return image;
    }
};