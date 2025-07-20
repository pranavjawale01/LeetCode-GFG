class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        total_sum = sum(nums)
        rem = total_sum % p
        if rem == 0:
            return 0
        
        prefix_map = {0: -1}
        prefix_sum = 0
        ans = len(nums)
        
        for i, num in enumerate(nums):
            prefix_sum += num
            curr_mod = prefix_sum % p
            target = (curr_mod - rem + p) % p
            
            if target in prefix_map:
                ans = min(ans, i - prefix_map[target])
                
            prefix_map[curr_mod] = i
        
        return ans if ans < len(nums) else -1