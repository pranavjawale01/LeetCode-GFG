class Solution:
    def prims(self, adj, V):
        pq = [(0, 0)]
        vis = [False] * V
        sum_cost = 0
        
        while pq:
            w, u = heapq.heappop(pq)
            if vis[u]:
                continue
            vis[u] = True
            sum_cost += w
            for nei, nwt in adj[u]:
                if not vis[nei]:
                    heapq.heappush(pq, (nwt, nei))
        
        return sum_cost

    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        V = len(points)
        adj = [[] for _ in range(V)]
        for i in range(V):
            for j in range(i + 1, V):
                x1, y1 = points[i]
                x2, y2 = points[j]
                d = abs(x1 - x2) + abs(y1 - y2)
                adj[i].append((j, d))
                adj[j].append((i, d))
        return self.prims(adj, V)