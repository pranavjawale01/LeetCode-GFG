class Solution:
    def totalNQueens(self, n: int) -> int:
        solutions = []
        board = [['.' for _ in range(n)] for _ in range(n)]
        self.solveNQueens(board, 0, solutions)
        return len(solutions)

    def solveNQueens(self, board, row, solutions):
        if row == len(board):
            solutions.append([''.join(row) for row in board])
            return
        for col in range(len(board)):
            if self.isSafe(board, row, col):
                board[row][col] = 'Q'
                self.solveNQueens(board, row + 1, solutions)
                board[row][col] = '.'

    def isSafe(self, board, row, col):
        for i in range(row):
            if board[i][col] == 'Q':
                return False
        for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
            if board[i][j] == 'Q':
                return False
        for i, j in zip(range(row, -1, -1), range(col, len(board))):
            if board[i][j] == 'Q':
                return False
        return True