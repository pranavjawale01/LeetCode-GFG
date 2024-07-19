class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        row, col = len(matrix), len(matrix[0])
        minRow = [float('inf')] * row
        maxCol = [float('-inf')] * col
        for i in range(row):
            for j in range(col):
                minRow[i] = min(minRow[i], matrix[i][j])
        
        for i in range(col):
            for j in range(row):
                maxCol[i] = max(maxCol[i], matrix[j][i])

        ans = []

        for i in range(row):
            for j in range(col):
                if maxCol[j] == minRow[i]:
                    ans.append(minRow[i])
        
        return ans