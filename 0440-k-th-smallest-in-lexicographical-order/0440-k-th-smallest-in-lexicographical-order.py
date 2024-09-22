class Solution:
    def Count(self, curr: int, next: int, n: int) -> int:
        countNum = 0
        while curr <= n:
            countNum += min(next, n + 1) - curr
            curr *= 10
            next *= 10
        return countNum

    def findKthNumber(self, n: int, k: int) -> int:
        curr = 1
        k -= 1
        while k > 0:
            count = self.Count(curr, curr + 1, n)
            if count <= k:
                curr += 1
                k -= count
            else:
                curr *= 10
                k -= 1
        return curr





# MLE
# class Solution:
#     def solve(self, curr, n, ans):
#         if curr > n:
#             return
#         ans.append(curr)
#         for digit in range(10):
#             nextnum = curr * 10 + digit
#             if nextnum > n:
#                 return
#             self.solve(nextnum, n, ans)
    
#     def findKthNumber(self, n: int, k: int) -> int:
#         ans = []
#         for i in range(1, 10):
#             self.solve(i, n, ans)
#         return ans[k - 1]