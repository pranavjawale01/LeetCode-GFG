class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        m, n = len(rowSum), len(colSum)
        arr = [[0 for _ in range(n)] for _ in range(m)]
        i, j = 0, 0
        while i < m and j < n:
            arr[i][j] = min(rowSum[i], colSum[j])
            rowSum[i] -= arr[i][j]
            colSum[j] -= arr[i][j]
            if rowSum[i] == 0:
                i += 1
            if colSum[j] == 0:
                j += 1
        return arr