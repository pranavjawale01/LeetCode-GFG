class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row = [[0 for _ in range(9)] for _ in range(9)]
        col = [[0 for _ in range(9)] for _ in range(9)]
        grid_3x3 = [[0 for _ in range(9)] for _ in range(9)]
        
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    continue
                num = int(board[i][j]) - 1
                k = (i // 3) * 3 + (j // 3)
                if row[i][num] or col[j][num] or grid_3x3[k][num]:
                    return False
                row[i][num] = col[j][num] = grid_3x3[k][num] = 1
        
        return True