class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        lastIndex, maxL = 0, 1
        dp , index = [1] * n, [-1] * n

        for i in range(n):
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    if dp[i] < dp[j] + 1:
                        dp[i] = dp[j] + 1
                        index[i] = j
                    if dp[i] > maxL:
                        maxL = dp[i]
                        lastIndex = i
        
        result = []
        while lastIndex >= 0:
            result.append(nums[lastIndex])
            lastIndex = index[lastIndex]

        return result