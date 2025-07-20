class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        rows , cols = len(grid) , len(grid[0])
        
        oneRow = [0 for _ in range(rows)]
        oneCol = [0 for _ in range(cols)]
        zeroRow = [0 for _ in range(rows)]
        zeroCol = [0 for _ in range(cols)]
        
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 0:
                    zeroRow[i] += 1
                    zeroCol[j] += 1
                elif grid[i][j] == 1:
                    oneRow[i] += 1
                    oneCol[j] += 1
        
        matrix = [[0 for _ in range(cols)] for _ in range(rows)]
        
        for i in range(rows):
            for j in range(cols):
                matrix[i][j] = oneRow[i] + oneCol[j] - zeroRow[i] - zeroCol[j]
                
        return matrix