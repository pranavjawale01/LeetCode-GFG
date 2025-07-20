class Solution:
    def tribonacci(self, n: int) -> int:
        memo = [-1] * (n + 1)
        return self.helper(n, memo)
    
    def helper(self, n, memo):
        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1
        if memo[n] != -1:
            return memo[n]
        memo[n] = self.helper(n - 1, memo) + self.helper(n - 2, memo) + self.helper(n - 3, memo)
        return memo[n]
        

# class Solution:
#     def tribonacci(self, n: int) -> int:
#         if n is 0:
#             return 0
#         if n is 1 or n is 2:
#             return 1
#         t0, t1, t2 = 0, 1, 1
#         for i in range(3, n+1):
#             temp = t0 + t1 + t2
#             t0 = t1
#             t1 = t2
#             t2 = temp
#         return t2