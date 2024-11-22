class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        ans = 0

        for curr in matrix:
            inv = [1 - x for x in curr]
            count = 0

            for row in matrix:
                if row == curr or row == inv:
                    count += 1

            ans = max(ans, count)

        return ans