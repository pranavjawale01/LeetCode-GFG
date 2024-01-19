class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        row = len(matrix)
        col = len(matrix[0]) if row > 0 else 0

        for i in range(1, row):
            for j in range(col):
                a = float('inf') if j - 1 < 0 else matrix[i-1][j-1]
                b = float('inf') if j + 1 >= col else matrix[i-1][j+1]
                matrix[i][j] += min(matrix[i-1][j], a, b)

        result = float('inf')
        for i in range(col):
            result = min(result, matrix[row-1][i])

        return result