class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        solutions = []
        board = [['.' for _ in range(n)] for _ in range(n)]
        self.solve(n, board, 0, solutions)
        return solutions

    def isSafe(self, row, col, n, board):
        for i in range(row):
            if board[i][col] == 'Q':
                return False
        for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
            if board[i][j] == 'Q':
                return False
        for i, j in zip(range(row, -1, -1), range(col, n)):
            if board[i][j] == 'Q':
                return False
        return True

    def solve(self, n, board, row, solutions):
        if row == n:
            solutions.append([''.join(row) for row in board])
            return
        for i in range(n):
            if self.isSafe(row, i, n, board):
                board[row][i] = 'Q'
                self.solve(n, board, row + 1, solutions)
                board[row][i] = '.'