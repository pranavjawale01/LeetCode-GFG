class Solution:
    def longestSubsequence(self, arr: List[int], diff: int) -> int:
        dp = {}
        n = len(arr)
        maxlen = 1
        for i in range(n):
            num = arr[i]
            if num - diff in dp:
                dp[num] = dp[num - diff] + 1
            else:
                dp[num] = 1
            maxlen = max(maxlen, dp[num])
        return maxlen