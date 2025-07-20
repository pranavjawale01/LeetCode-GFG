class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        m = len(matrix[0])
        total_sum = 0
        neg_count = 0
        min_element = float('inf')

        for i in range(n):
            for j in range(m):
                total_sum += abs(matrix[i][j])
                if matrix[i][j] < 0:
                    neg_count += 1
                min_element = min(min_element, abs(matrix[i][j]))

        if neg_count % 2 == 0:
            return total_sum
        return total_sum - 2 * min_element