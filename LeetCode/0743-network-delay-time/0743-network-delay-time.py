class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = {}
        for u, v, w in times:
            if u not in graph:
                graph[u] = []
            graph[u].append((v, w))
        
        pq = [(0, k)]
        dist = {i: sys.maxsize for i in range(1, n + 1)}
        dist[k] = 0
        
        while pq:
            d, node = heapq.heappop(pq)
            
            if d > dist[node]:
                continue
            
            if node in graph:
                for neighbor, weight in graph[node]:
                    new_dist = d + weight
                    if new_dist < dist[neighbor]:
                        dist[neighbor] = new_dist
                        heapq.heappush(pq, (new_dist, neighbor))
        
        max_delay = max(dist.values())
        
        if max_delay == sys.maxsize:
            return -1
        
        return max_delay