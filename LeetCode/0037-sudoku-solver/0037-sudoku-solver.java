class Solution {
    public boolean check(char[][] board, int row, int col, char ch) {
        for(int i=0; i<9 ; i++) {
            if(board[row][i] == ch) {
                return false;
            }
            if(board[i][col] == ch) {
                return false;
            }
            if(board[(row/3)*3+i/3][(col/3)*3+i%3] == ch) {
                return false;
            }
        }
        return true;
    }

    public boolean backTracking(char[][] board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') {
                    for(char ch='1'; ch<='9'; ch++) {
                        if(check(board,i,j,ch)) {
                            board[i][j] = ch;
                            if(backTracking(board) == true) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    public void solveSudoku(char[][] board) {
        backTracking(board);
    }
}