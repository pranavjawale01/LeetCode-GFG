class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        for (int i = 0; i < moves.size(); ++i) {
            int row = moves[i][0];
            int col = moves[i][1];
            char player = (i % 2 == 0) ? 'X' : 'O';
            board[row][col] = player;
            
            if (board[row][0] == player && board[row][1] == player && board[row][2] == player) {
                return player == 'X' ? "A" : "B";
            }
            if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
                return player == 'X' ? "A" : "B";
            }
            if (row == col && board[0][0] == player && board[1][1] == player && board[2][2] == player) {
                return player == 'X' ? "A" : "B";
            }
            if (row + col == 2 && board[0][2] == player && board[1][1] == player && board[2][0] == player) {
                return player == 'X' ? "A" : "B";
            }
        }
        if (moves.size() == 9) {
            return "Draw";
        }
        return "Pending";
    }
};