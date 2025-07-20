class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        OR = 0
        for x in nums:
            OR = OR | x
        count = [0]
        def solve(i: int, ans: int):
            if i >= len(nums):
                if ans == OR:
                    count[0] += 1
                return
            solve(i + 1, ans | nums[i])
            solve(i + 1, ans)        
        solve(0, 0)
        return count[0] 