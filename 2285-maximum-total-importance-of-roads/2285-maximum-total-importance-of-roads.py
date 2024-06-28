class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        degree = [0] * n
        for road in roads:
            degree[road[0]] += 1
            degree[road[1]] += 1
        val = 1
        sum_ = 0
        degree.sort()
        for i in range(n):
            sum_ += val * degree[i]
            val += 1
        return sum_