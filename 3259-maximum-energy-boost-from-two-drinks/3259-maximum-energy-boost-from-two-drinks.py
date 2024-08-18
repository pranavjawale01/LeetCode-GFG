class Solution:
    def maxEnergyBoost(self, A: List[int], B: List[int]) -> int:
        A1 = B1 = A2 = B2 = 0
        for i in range(0 , len(A)):
            currA = A[i] + max(A1, B2)
            currB = B[i] + max(B1, A2)
            A2 , A1 = A1 , currA
            B2 , B1 = B1 , currB
        return max(A1 , B1)





# class Solution:
#     def __init__(self):
#         self.n = 0
#         self.dp = []

#     def solve(self, i: int, j: int, a: List[int], b: List[int]) -> int:
#         if i >= self.n:
#             return 0
#         if self.dp[i][j] != -1:
#             return self.dp[i][j]
        
#         ans = a[i] if j == 0 else b[i]
#         ans += max(self.solve(i + 1, j, a, b), self.solve(i + 2, 1 - j, a, b))
#         self.dp[i][j] = ans
#         return ans

#     def maxEnergyBoost(self, energyDrinkA: List[int], energyDrinkB: List[int]) -> int:
#         self.n = len(energyDrinkA)
#         self.dp = [[-1 for _ in range(2)] for _ in range(self.n)]
#         return max(self.solve(0, 0, energyDrinkA, energyDrinkB), self.solve(0, 1, energyDrinkA, energyDrinkB))