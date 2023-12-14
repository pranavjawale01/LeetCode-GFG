class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (searchWord(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
private:
    bool searchWord(vector<vector<char>>& board, const string& word, int index, int i, int j) {
        if (index == word.length()) {
            return true;
        }
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = ' ';
        
        bool found = searchWord(board, word, index + 1, i + 1, j) ||
                     searchWord(board, word, index + 1, i - 1, j) ||
                     searchWord(board, word, index + 1, i, j + 1) ||
                     searchWord(board, word, index + 1, i, j - 1);
        
        board[i][j] = temp;
        
        return found;
    }
};