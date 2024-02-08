class Solution:
    def numSquares(self, n: int) -> int:
        arr = [100001] * (n + 1)
        arr[0] = 0
        for i in range(1, n+1):
            for j in range(1, int(i**0.5) + 1):
                arr[i] = min(arr[i], 1 + arr[i - j*j])
        return arr[n]    

# class Solution:
#     def numSquares(self, n: int) -> int:
#         memo = [-1] * (n + 1)

#         def solve(n):
#             if n == 0:
#                 return 0
#             if memo[n] != -1:
#                 return memo[n]
#             minCount = float('inf')
#             for i in range(1, int(n ** 0.5) + 1):
#                 result = 1 + solve(n - i * i)
#                 minCount = min(minCount, result)
#             memo[n] = minCount
#             return memo[n]

#         return solve(n)