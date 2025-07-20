class Solution:
    def check(self, num: int, curr: int, target: int) -> bool:
        if num == 0:
            return curr == target
        return (self.check(num // 10, curr + num % 10, target) or
                self.check(num // 100, curr + num % 100, target) or
                self.check(num // 1000, curr + num % 1000, target) or
                self.check(num // 10000, curr + num % 10000, target))

    def punishmentNumber(self, n: int) -> int:
        ans = 0
        for i in range(1, n + 1):
            sq = i * i
            if self.check(sq, 0, i):
                ans += sq
        return ans




# class Solution:
#     def solve(self, i, currSum, s, num, dp):
#         if i == len(s):
#             return currSum == num
#         if currSum > num:
#             return False
#         if dp[i][currSum] != -1:
#             return dp[i][currSum]
#         flag = False
#         for j in range(i, len(s)):
#             currStr = s[i:j+1]
#             added = int(currStr)
#             flag |= self.solve(j+1, currSum + added, s, num, dp)
#             if flag:
#                 dp[i][currSum] = 1
#                 return True

#         dp[i][currSum] = 0
#         return False

#     def punishmentNumber(self, n: int) -> int:
#         ans = 0
#         for i in range(1, n+1):
#             sq = i * i
#             s = str(sq)
#             dp = [[-1] * (i+1) for _ in range(len(s))]
#             if self.solve(0, 0, s, i, dp):
#                 ans += sq
#         return ans