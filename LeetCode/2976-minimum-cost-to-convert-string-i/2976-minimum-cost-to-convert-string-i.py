class Solution:
    def dijkstra(self, s, adj, arr):
        pq = []
        dist = [sys.maxsize] * 26
        dist[ord(s) - ord('a')] = 0
        heapq.heappush(pq, (0, s))
        
        while pq:
            d, n = heapq.heappop(pq)
            
            if d > dist[ord(n) - ord('a')]:
                continue
            
            for node, cost in adj[n]:
                if dist[ord(node) - ord('a')] > d + cost:
                    dist[ord(node) - ord('a')] = d + cost
                    heapq.heappush(pq, (d + cost, node))
        
        for i in range(26):
            arr[ord(s) - ord('a')][i] = dist[i]


    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        adj = defaultdict(list)
        for i in range(len(original)):
            adj[original[i]].append((changed[i], cost[i]))
        
        arr = [[sys.maxsize] * 26 for _ in range(26)]
        
        for c in range(26):
            self.dijkstra(chr(ord('a') + c), adj, arr)
        
        ans = 0
        n = len(source)
        
        for i in range(n):
            u = ord(source[i]) - ord('a')
            v = ord(target[i]) - ord('a')
            if arr[u][v] == sys.maxsize:
                return -1
            ans += arr[u][v]
        
        return ans











# class Solution:
#     def bellmanFord(self, arr, s):
#         V = len(arr)
#         dist = [sys.maxsize] * V
#         dist[s] = 0
#         for i in range(V-1):
#             for u in range(V):
#                 for v in range(V):
#                     if dist[u] != sys.maxsize and dist[u] + arr[u][v] < dist[v]:
#                         dist[v] = dist[u] + arr[u][v]
#         for i in range(V):
#             arr[s][i] = dist[i]

#     def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
#         arr = [[sys.maxsize for _ in range(26)] for _ in range(26)]
#         n = len(original)
#         for i in range(n):
#             u = ord(original[i]) - ord('a')
#             v = ord(changed[i])  - ord('a')
#             arr[u][v] = min(cost[i], arr[u][v])

#         for i in range(26):
#             arr[i][i] = 0
        
#         for i in range(26):
#             self.bellmanFord(arr, i)

#         n = len(target)

#         ans = 0

#         for i in range(n):
#             u = ord(source[i]) - ord('a')
#             v = ord(target[i]) - ord('a')
#             if arr[u][v] == sys.maxsize:
#                 return -1
#             ans += arr[u][v]
        
#         return ans










# class Solution:
#     def floydWarshall(self, arr):
#         for via in range(26):
#             for i in range(26):
#                 for j in range(26):
#                     arr[i][j] = min(arr[i][j], arr[i][via] + arr[via][j])

#     def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
#         arr = [[sys.maxsize for _ in range(26)] for _ in range(26)]
#         n = len(original)
#         for i in range(n):
#             u = ord(original[i]) - ord('a')
#             v = ord(changed[i])  - ord('a')
#             arr[u][v] = min(cost[i], arr[u][v])

#         for i in range(26):
#             arr[i][i] = 0
        
#         self.floydWarshall(arr)

#         n = len(target)

#         ans = 0

#         for i in range(n):
#             u = ord(source[i]) - ord('a')
#             v = ord(target[i]) - ord('a')
#             if arr[u][v] == sys.maxsize:
#                 return -1
#             ans += arr[u][v]
        
#         return ans