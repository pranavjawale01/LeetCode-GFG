public class Solution {
    public boolean isValidSudoku(char[][] board) {
        int[][] row = new int[9][9];
        int[][] col = new int[9][9];
        int[][] grid_3x3 = new int[9][9];
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    continue;
                }
                int num = board[i][j] - '1';
                int k = (i / 3) * 3 + (j / 3);
                if(row[i][num] == 1 || col[j][num] == 1 || grid_3x3[k][num] == 1) {
                    return false;
                }
                row[i][num] = col[j][num] = grid_3x3[k][num] = 1;
            }
        }
        return true;
    }
}