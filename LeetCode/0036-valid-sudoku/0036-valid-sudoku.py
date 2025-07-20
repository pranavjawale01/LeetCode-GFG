class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row = [{} for _ in range(9)]
        col = [{} for _ in range(9)]
        grid_3x3 = [{} for _ in range(9)]
        
        for i in range(9):
            for j in range(9):
                num = board[i][j]
                if num == '.':
                    continue
                
                k = (i // 3) * 3 + (j // 3)
                if num in row[i] or num in col[j] or num in grid_3x3[k]:
                    return False
                
                row[i][num] = col[j][num] = grid_3x3[k][num] = 1
        
        return True