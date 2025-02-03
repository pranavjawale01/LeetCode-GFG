class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        ans = 1
        inc = dec = 1
        n = len(nums)
        
        for i in range(n - 1):
            if nums[i] < nums[i + 1]:
                inc += 1
            else:
                inc = 1
            
            if nums[i] > nums[i + 1]:
                dec += 1
            else:
                dec = 1
            
            ans = max(ans, inc, dec)
        
        return ans