class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        indegree = [0] * n
        for x in edges:
            indegree[x[1]] += 1
        ans, freq = -1, 0
        for i in range(n):
            if indegree[i] == 0:
                ans = i
                freq += 1
                if freq > 1:
                    return -1
        return ans