class Solution {
    public boolean exist(char[][] board, String word) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (searchWord(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    private boolean searchWord(char[][] board, String word, int index, int i, int j) {
        if (index == word.length()) {
            return true;
        }
        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] != word.charAt(index)) {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = ' ';
        
        boolean found = searchWord(board, word, index + 1, i + 1, j) ||
                        searchWord(board, word, index + 1, i - 1, j) ||
                        searchWord(board, word, index + 1, i, j + 1) ||
                        searchWord(board, word, index + 1, i, j - 1);
        board[i][j] = temp;
        return found;
    }
}