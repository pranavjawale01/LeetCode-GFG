class Solution:
    def __init__(self):
        self.parent = []
        self.rank = []

    def find(self, x):
        if x == self.parent[x]:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        x_parent = self.find(x)
        y_parent = self.find(y)

        if x_parent == y_parent:
            return

        if self.rank[x_parent] > self.rank[y_parent]:
            self.parent[y_parent] = x_parent
        elif self.rank[x_parent] < self.rank[y_parent]:
            self.parent[x_parent] = y_parent
        else:
            self.parent[x_parent] = y_parent
            self.rank[y_parent] += 1

    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        V = len(points)
        self.parent = list(range(V))
        self.rank = [0] * V

        edges = []
        for i in range(V):
            for j in range(i + 1, V):
                x1, y1 = points[i]
                x2, y2 = points[j]
                d = abs(x1 - x2) + abs(y1 - y2)
                edges.append((d, i, j))

        edges.sort()

        sum_cost = 0
        for d, u, v in edges:
            if self.find(u) != self.find(v):
                self.union(u, v)
                sum_cost += d

        return sum_cost








# class Solution:
#     def prims(self, adj, V):
#         pq = [(0, 0)]
#         vis = [False] * V
#         sum_cost = 0
        
#         while pq:
#             w, u = heapq.heappop(pq)
#             if vis[u]:
#                 continue
#             vis[u] = True
#             sum_cost += w
#             for nei, nwt in adj[u]:
#                 if not vis[nei]:
#                     heapq.heappush(pq, (nwt, nei))
        
#         return sum_cost

#     def minCostConnectPoints(self, points: List[List[int]]) -> int:
#         V = len(points)
#         adj = [[] for _ in range(V)]
#         for i in range(V):
#             for j in range(i + 1, V):
#                 x1, y1 = points[i]
#                 x2, y2 = points[j]
#                 d = abs(x1 - x2) + abs(y1 - y2)
#                 adj[i].append((j, d))
#                 adj[j].append((i, d))
#         return self.prims(adj, V)