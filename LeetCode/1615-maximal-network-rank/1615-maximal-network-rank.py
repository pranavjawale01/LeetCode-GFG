class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        connected = [[False] * n for _ in range(n)]
        count = [0] * n

        for road in roads:
            count[road[0]] += 1
            count[road[1]] += 1
            connected[road[0]][road[1]] = True
            connected[road[1]][road[0]] = True

        res = 0

        for i in range(n):
            for j in range(i + 1, n):
                rank = count[i] + count[j] - (connected[i][j] == True)
                res = max(res, rank)

        return res