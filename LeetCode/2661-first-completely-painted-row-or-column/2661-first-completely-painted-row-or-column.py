class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        mp = {mat[i][j]: (i, j) for i in range(m) for j in range(n)}
        rowCount = [0] * m
        colCount = [0] * n
        for i, val in enumerate(arr):
            row, col = mp[val]
            rowCount[row] += 1
            colCount[col] += 1
            if rowCount[row] == n or colCount[col] == m:
                return i
        return -1