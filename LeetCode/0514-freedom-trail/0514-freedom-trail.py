class Solution:
    def countSteps(self, ringIndex: int, i: int, n: int) -> int:
        dist = abs(i - ringIndex)
        wrapAround = n - dist
        return min(dist, wrapAround)

    def findRotateSteps(self, ring: str, key: str) -> int:
        n = len(ring)
        m = len(key)
        dp = [[float('inf') for _ in range(m+1)] for _ in range(n)]
        for i in range(n):
            dp[i][m] = 0
        for keyIndex in range(m - 1, -1, -1):
            for ringIndex in range(n):
                result = float('inf')
                for i in range(n):
                    if ring[i] == key[keyIndex]:
                        totalSteps = self.countSteps(ringIndex, i, n) + 1 + dp[i][keyIndex+1]
                        result = min(result, totalSteps)
                dp[ringIndex][keyIndex] = result
        return dp[0][0]



# class Solution:
#     def countSteps(self, ringIndex: int, i: int, n: int) -> int:
#         dist = abs(i - ringIndex)
#         wrapAround = n - dist
#         return min(dist, wrapAround)

#     def solve(self, ringIndex: int, keyIndex: int, ring: str, key: str) -> int:
#         if keyIndex == len(key):
#             return 0
#         if self.dp[ringIndex][keyIndex] != -1:
#             return self.dp[ringIndex][keyIndex]

#         result = float('inf')

#         for i in range(len(ring)):
#             if ring[i] == key[keyIndex]:
#                 totalSteps = self.countSteps(ringIndex, i, len(ring)) + 1 + self.solve(i, keyIndex + 1, ring, key)
#                 result = min(result, totalSteps)
#         self.dp[ringIndex][keyIndex] = result
#         return result

#     def findRotateSteps(self, ring: str, key: str) -> int:
#         self.dp = [[-1] * 101 for _ in range(101)]
#         return self.solve(0, 0, ring, key)