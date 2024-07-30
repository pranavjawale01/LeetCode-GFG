class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        
        t = [0] * (n + 1)
        
        result1 = 0
        result2 = 0
        
        t[0] = 0
        for i in range(1, n):
            t[i] = max(t[i - 1], nums[i - 1] + (t[i - 2] if i - 2 >= 0 else 0))
        result1 = t[n - 1]
        
        t = [0] * (n + 1)
        t[0] = 0
        t[1] = 0
        for i in range(2, n + 1):
            t[i] = max(t[i - 1], nums[i - 1] + (t[i - 2] if i - 2 >= 0 else 0))
        result2 = t[n]
        
        return max(result1, result2)




# class Solution:
#     def rob(self, nums: List[int]) -> int:
#         n = len(nums)
#         if n == 1:
#             return nums[0]
#         if n == 2:
#             return max(nums[0], nums[1])
        
#         def solve(nums):
#             memo = [-1] * len(nums)
#             def dp(i):
#                 if i >= len(nums):
#                     return 0
#                 if memo[i] != -1:
#                     return memo[i]
#                 take = nums[i] + dp(i + 2)
#                 skip = dp(i + 1)
#                 memo[i] = max(take, skip)
#                 return memo[i]
#             return dp(0)
        
#         zero = solve(nums[:-1])
#         one = solve(nums[1:])
        
#         return max(zero, one)