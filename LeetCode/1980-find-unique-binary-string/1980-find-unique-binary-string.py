class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        st = {int(x, 2) for x in nums}
        n = len(nums)
        for num in range(0, n + 1):
            if num not in st:
                ans = format(num, '016b')
                return ans[16-n:]





# class Solution:
#     def findDifferentBinaryString(self, nums: List[str]) -> str:
#         n = len(nums)
#         ans = ""
        
#         for i in range(n):
#             ch = nums[i][i]
#             ans += '1' if ch == '0' else '0'
        
#         return ans





# # class Solution:
# #     def __init__(self):
# #         self.st = set()
# #         self.ans = ""

# #     def solve(self, curr, n):
# #         if len(curr) == n:
# #             if curr not in self.st:
# #                 self.ans = curr
# #             return
# #         if self.ans:
# #             return

# #         self.solve(curr + '0', n)
# #         self.solve(curr + '1', n)

# #     def findDifferentBinaryString(self, nums: List[str]) -> str:
# #         self.st = set(nums)
# #         self.solve("", len(nums[0]))
# #         return self.ans