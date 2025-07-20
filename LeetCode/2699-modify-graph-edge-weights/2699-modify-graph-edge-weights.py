class Solution:

    INF = int(2e9)

    def dijkstra(self, n, src, dest, adj):
        dist = [self.INF] * n
        dist[src] = 0
        pq = [(0, src)]
        while pq:
            d, u = heapq.heappop(pq)
            if d > dist[u]:
                continue
            for v, w in adj[u]:
                if w + d < dist[v]:
                    dist[v] = w + d
                    heapq.heappush(pq, (dist[v], v))
        return dist[dest]

    def modifiedGraphEdges(self, n: int, edges: List[List[int]], source: int, destination: int, target: int) -> List[List[int]]:
        adj = [[] for _ in range(n)]
        for a, b, c in edges:
            if c != -1:
                adj[a].append((b, c))
                adj[b].append((a, c))
        initialDist = self.dijkstra(n, source, destination, adj)
        if initialDist < target:
            return []
        flag = target == initialDist
        for x in edges:
            a, b, c = x
            if c == -1:
                x[2] = self.INF if flag else 1
                if not flag:
                    adj[a].append((b, x[2]))
                    adj[b].append((a, x[2]))
                    newShortDist = self.dijkstra(n, source, destination, adj)
                    if newShortDist <= target:
                        flag = True
                        x[2] += target - newShortDist
        if not flag:
            return []
        return edges