class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int row = img.size(), col = img[0].size();
        vector<vector<int>> rImg(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int count = 0, total = 0;
                for (int ni = max(0, i-1); ni < min(row, i+2); ni++) {
                    for (int nj = max(0, j-1); nj < min(col, j+2); nj++) {
                        total += img[ni][nj];
                        count += 1;
                    }
                }
                rImg[i][j] = total / count;
            }
        }
        return rImg;
    }
};