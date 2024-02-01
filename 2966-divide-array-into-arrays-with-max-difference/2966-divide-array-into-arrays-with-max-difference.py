class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        n = len(nums)
        result = []
        
        nums.sort()
        
        for i in range(0, n-2, 3):
            if nums[i+2] - nums[i] > k:
                return []
            
            result.append([nums[i], nums[i+1], nums[i+2]])
        
        return result
