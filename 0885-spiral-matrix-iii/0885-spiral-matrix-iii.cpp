class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int step = 0;
        int dir = 0;
        ans.push_back({rStart, cStart});
        while (ans.size() < rows * cols) {
            if (dir == 0 || dir == 2) {
                step++;
            }
            for (int i = 0; i < step; i++) {
                rStart += dirs[dir][0];
                cStart += dirs[dir][1];
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    ans.push_back({rStart, cStart});
                }
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};