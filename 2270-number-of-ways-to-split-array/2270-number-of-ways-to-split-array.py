class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        n = len(nums)
        pref = [0] * n
        pref[0] = nums[0]
        for i in range(1, n):
            pref[i] = pref[i-1] + nums[i]
        ans = 0
        for i in range(0, n-1):
            left = pref[i]
            right = pref[n-1] - pref[i]
            if left >= right:
                ans += 1
        return ans