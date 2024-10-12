class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        def solve(val: int) -> int:
            ans = float('inf')
            for i in range(32):
                num = val & ~(1 << i)
                if num < 0:
                    continue
                if (num | (num + 1) == val):
                    ans = min(ans, num)
            return -1 if ans == float('inf') else ans
        
        n = len(nums)
        ans = [-1] * n
        for i in range(n):
            ans[i] = solve(nums[i])
        return ans