class Solution:
    def jump(self, nums: List[int]) -> int:
        maxReach , steps , lastJump = 0 , 0 , 0
        for i in range(len(nums) - 1):
            maxReach = max(maxReach, i + nums[i])
            if i == lastJump :
                steps += 1
                lastJump = maxReach
        return steps