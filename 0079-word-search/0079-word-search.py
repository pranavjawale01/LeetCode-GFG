class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        for i in range(len(board)):
            for j in range(len(board[0])):
                if (self.searchWord(board, word, 0, i, j)):
                    return True
        return False

    def searchWord(self, board: List[List[str]], word: str, index: int, i: int, j: int) -> bool:
        if index == len(word):
            return True
        if i < 0 or j < 0 or i >= len(board) or j >= len(board[0]) or board[i][j] != word[index]:
            return False

        temp = board[i][j]
        board[i][j] = ' '

        result = self.searchWord(board, word, index + 1, i + 1, j) or \
                 self.searchWord(board, word, index + 1, i - 1, j) or \
                 self.searchWord(board, word, index + 1, i, j + 1) or \
                 self.searchWord(board, word, index + 1, i, j - 1)
        board[i][j] = temp

        return result