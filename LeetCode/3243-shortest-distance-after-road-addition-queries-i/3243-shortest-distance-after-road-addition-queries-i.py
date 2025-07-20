class Solution:
    def dijikstra(self, s, n, mp):
        dist = [n] * n
        q = deque([s])
        dist[s] = 0
        while q:
            u = q.popleft()
            for v in mp[u]:
                if dist[u] + 1 < dist[v]:
                    dist[v] = dist[u] + 1
                    q.append(v)
        return dist[n - 1]

    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        ans = []
        mp = [[] for _ in range(n)]
        for i in range(n - 1):
            mp[i].append(i + 1)
        for query in queries:
            mp[query[0]].append(query[1])
            ans.append(self.dijikstra(0, n, mp))
        return ans