class Solution:
    def minOperations(self, nums: List[int]) -> int:
        def solve(n1: int, n2: int) -> int:
            for i in range(n1, 1, -1):
                if n2 % i == 0:
                    return i
            return -1
        count = 0
        for i in range(len(nums) - 1, 0, -1):
            if nums[i] < nums[i-1]:
                nums[i-1] = solve(nums[i], nums[i-1])
                if nums[i-1] == -1:
                    return -1
                count += 1
        return count