class Solution:
    def __init__(self):
        self.dp = [[-1] * 4 for _ in range(20001)]

    def helper(self, sums: List[int], k: int, i: int, rem: int) -> int:
        if rem == 0:
            return 0
        if i >= len(sums):
            return float('-inf')
        if self.dp[i][rem] != -1:
            return self.dp[i][rem]
        take = sums[i] + self.helper(sums, k, i + k, rem - 1)
        not_take = self.helper(sums, k, i + 1, rem)
        self.dp[i][rem] = max(take, not_take)
        return self.dp[i][rem]

    def solve(self, sums: List[int], k: int, i: int, rem: int, idx: List[int]) -> None:
        if rem == 0 or i >= len(sums):
            return
        take = sums[i] + self.helper(sums, k, i + k, rem - 1)
        not_take = self.helper(sums, k, i + 1, rem)
        if take >= not_take:
            idx.append(i)
            self.solve(sums, k, i + k, rem - 1, idx)
        else:
            self.solve(sums, k, i + 1, rem, idx)

    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        n = len(nums) - k + 1
        sums = []
        sum_ = 0
        i, j = 0, 0

        while j < len(nums):
            sum_ += nums[j]
            if j - i + 1 == k:
                sums.append(sum_)
                sum_ -= nums[i]
                i += 1
            j += 1

        idx = []
        self.solve(sums, k, 0, 3, idx)
        return idx