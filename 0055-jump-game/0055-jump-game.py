class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n , max_reach = len(nums) - 1, 0
        
        for i in range(len(nums)):
            if i > max_reach:
                return False
            
            max_reach = max(max_reach, i + nums[i])
            
            if max_reach >= n:
                return True
            
        return False