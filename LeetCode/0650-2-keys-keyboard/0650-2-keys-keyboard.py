class Solution:
    def minSteps(self, n: int) -> int:
        if n == 1:
            return 0
        if n == 2:
            return 2
        
        dp = [0] * (n + 1)
        dp[0] = 0
        dp[1] = 0
        dp[2] = 2
        
        for i in range(3, n + 1):
            factor = i // 2
            while factor >= 1:
                if i % factor == 0:
                    steps_to_print_factor_as = dp[factor]
                    copy = 1
                    paste = (i // factor) - 1
                    dp[i] = steps_to_print_factor_as + copy + paste
                    break
                else:
                    factor -= 1
        
        return dp[n]





# class Solution:
#     def __init__(self):
#         self.dp = [[-1 for _ in range(1001)] for _ in range(1001)]

#     def solve(self, currA: int, pasteA: int, n: int) -> int:
#         if currA == n:
#             return 0
#         if currA > n:
#             return 1000
        
#         if self.dp[currA][pasteA] != -1:
#             return self.dp[currA][pasteA]
        
#         copyPaste = 2 + self.solve(currA + currA, currA, n)
        
#         paste = 1 + self.solve(currA + pasteA, pasteA, n)
        
#         self.dp[currA][pasteA] = min(copyPaste, paste)
#         return self.dp[currA][pasteA]

#     def minSteps(self, n: int) -> int:
#         if n == 1:
#             return 0
        
#         return 1 + self.solve(1, 1, n)