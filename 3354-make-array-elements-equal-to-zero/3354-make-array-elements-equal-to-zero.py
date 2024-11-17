class Solution:
    def solve(self, nums, i, dir):
        n = len(nums)
        while 0 <= i < n:
            if nums[i] == 0:
                i += dir
            else:
                nums[i] -= 1
                dir = -dir
                i += dir
        return all(x == 0 for x in nums)

    def countValidSelections(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        for i in range(n):
            if nums[i] == 0:
                if self.solve(nums[:], i, -1):
                    ans += 1
                if self.solve(nums[:], i, 1):
                    ans += 1
        return ans