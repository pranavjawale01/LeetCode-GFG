class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result: List[List[int]] = []

        def backTrack(nums: List[int], start: int):
            if start == len(nums) - 1:
                result.append(nums.copy())
                return
            for i in range(start, len(nums)):
                nums[i], nums[start] = nums[start], nums[i]
                backTrack(nums, start + 1)
                nums[i], nums[start] = nums[start], nums[i]

        backTrack(nums, 0)
        return result