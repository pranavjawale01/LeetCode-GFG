class Solution:
    def check(self, board, row, col, ch):
        for i in range(9):
            if board[row][i] == ch or board[i][col] == ch or board[(row//3)*3 + i//3][(col//3)*3 + i%3] == ch:
                return False
        return True

    def backTracking(self, board):
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    for ch in '123456789':
                        if self.check(board, i, j, ch):
                            board[i][j] = ch
                            if self.backTracking(board):
                                return True
                            board[i][j] = '.'
                    return False
        return True

    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.backTracking(board)