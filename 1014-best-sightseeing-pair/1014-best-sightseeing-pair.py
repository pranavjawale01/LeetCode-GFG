class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        n = len(values)
        ans = 0
        maxval = values[0] + 0
        for j in range(1, n):
            x = values[j] - j
            y = maxval
            ans = max(ans, x + y)
            maxval = max(maxval, values[j] + j)
        return ans