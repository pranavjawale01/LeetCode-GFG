class Solution:
    def __init__(self):
        self.parent = []
        self.rank = []
        self.n = 0

    def find(self, i):
        if self.parent[i] != i:
            self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u != root_v:
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1

    def removeStones(self, stones: List[List[int]]) -> int:
        self.n = len(stones)
        self.parent = [i for i in range(self.n)]
        self.rank = [1] * self.n
        for i in range(self.n):
            for j in range(i + 1, self.n):
                if stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]:
                    self.union(i, j)
        groups = sum(1 for i in range(self.n) if self.find(i) == i)
        return self.n - groups







# class Solution:
    
#     def __init__(self):
#         self.n = 0
    
#     def dfs(self, stones: List[List[int]], idx: int, vis: List[bool]) -> None:
#         vis[idx] = True
#         for i in range(self.n):
#             if not vis[i] and (stones[i][0] == stones[idx][0] or stones[i][1] == stones[idx][1]):
#                 self.dfs(stones, i, vis)
    
#     def removeStones(self, stones: List[List[int]]) -> int:
#         self.n = len(stones)
#         vis = [False] * self.n
#         count = 0
#         for i in range(self.n):
#             if vis[i]:
#                 continue
#             self.dfs(stones, i, vis)
#             count += 1
#         return self.n - count