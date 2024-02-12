class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count , n , element = 1, len(nums), nums[0]
        for i in range(1, n):
            if count is 0:
                element = nums[i]
                count += 1
            elif nums[i] is element:
                count += 1
            else:
                count -= 1
        return element