class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        n = len(nums)
        ans = float('inf')

        for sz in range(l, r + 1):
            curr = 0

            for i in range(sz):
                curr += nums[i]
            if curr > 0:
                ans = min(ans, curr)

            for i in range(sz, n):
                curr += nums[i] - nums[i - sz]
                if curr > 0:
                    ans = min(ans, curr)

        return -1 if ans == float('inf') else ans