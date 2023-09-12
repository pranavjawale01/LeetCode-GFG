class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        map = {}
        for i in range(n):
            remaining = target - nums[i]
            if remaining in map:
                return [i,map[remaining]]
            map[nums[i]] = i
        return []