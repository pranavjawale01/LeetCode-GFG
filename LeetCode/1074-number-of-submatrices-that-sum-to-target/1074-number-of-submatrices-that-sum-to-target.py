class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        row, col = len(matrix), len(matrix[0])

        for i in range(row):
            for j in range(1, col):
                matrix[i][j] += matrix[i][j-1]

        result = 0

        for i in range(col):
            for j in range(i, col):
                mp = defaultdict(int)
                mp[0] = 1
                cum_sum = 0
                for k in range(row):
                    cum_sum += matrix[k][j] - (matrix[k][i-1] if i > 0 else 0)
                    if cum_sum - target in mp:
                        result += mp[cum_sum - target]
                    mp[cum_sum] += 1
                
        return result