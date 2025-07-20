class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        distance = [float('inf')] * n
        adj = defaultdict(list)

        for flight in flights:
            u, v, cost = flight
            adj[u].append((v, cost))

        q = deque([(src, 0)])
        distance[src] = 0
        level = 0

        while q and level <= k:
            size = len(q)
            for _ in range(size):
                u, d = q.popleft()
                for v, cost in adj[u]:
                    if distance[v] > d + cost:
                        distance[v] = d + cost
                        q.append((v, d + cost))
            level += 1

        return distance[dst] if distance[dst] != float('inf') else -1