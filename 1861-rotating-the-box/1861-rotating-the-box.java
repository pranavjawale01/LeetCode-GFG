class Solution {
    public char[][] rotateTheBox(char[][] box) {
        int m = box.length, n = box[0].length;
        char[][] ans = new char[n][m];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][m - 1 - i] = box[i][j];
            }
        }

        for (int j = 0; j < m; j++) {
            for (int i = n - 1; i >= 0; i--) {
                if (ans[i][j] == '.') {
                    int stoneRow = -1;
                    for (int k = i - 1; k >= 0; k--) {
                        if (ans[k][j] == '*') break;
                        if (ans[k][j] == '#') {
                            stoneRow = k;
                            break;
                        }
                    }
                    if (stoneRow != -1) {
                        ans[i][j] = '#';
                        ans[stoneRow][j] = '.';
                    }
                }
            }
        }
        return ans;
    }
}