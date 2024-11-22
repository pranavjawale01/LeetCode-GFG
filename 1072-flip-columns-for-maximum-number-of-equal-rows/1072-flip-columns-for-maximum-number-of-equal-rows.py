class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        pattern_count = defaultdict(int)

        for row in matrix:
            pattern = []
            first_value = row[0]

            for value in row:
                pattern.append('p' if value == first_value else 'j')

            pattern_str = ''.join(pattern)
            pattern_count[pattern_str] += 1

        return max(pattern_count.values())











# class Solution:
#     def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
#         m, n = len(matrix), len(matrix[0])
#         ans = 0

#         for curr in matrix:
#             inv = [1 - x for x in curr]
#             count = 0

#             for row in matrix:
#                 if row == curr or row == inv:
#                     count += 1

#             ans = max(ans, count)

#         return ans