class Solution:
    def flyodWarshall(self, n: int, spm) -> None:
        for via in range(n):
            for i in range(n):
                for j in range(n):
                    if spm[i][via] < sys.maxsize and spm[via][j] < sys.maxsize:
                        spm[i][j] = min(spm[i][j], spm[i][via] + spm[via][j])

    def findResultCity(self, n: int, spm: List[List[int]], distanceThreshold: int) -> int:
        resultCity = -1
        leastReachCount = sys.maxsize
        for i in range(n):
            countReach = sum(1 for j in range(n) if i != j and spm[i][j] <= distanceThreshold)
            if countReach < leastReachCount or (countReach == leastReachCount and i > resultCity):
                leastReachCount = countReach
                resultCity = i
        return resultCity

    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        spm = [[sys.maxsize] * n for _ in range(n)]
        for i in range(n):
            spm[i][i] = 0
        
        for u, v, w in edges:
            spm[u][v] = w
            spm[v][u] = w
        
        self.flyodWarshall(n, spm)

        return self.findResultCity(n, spm, distanceThreshold)









# class Solution:
#     def bellmanFord(self, n: int, edges , result: List[int], s: int) -> None:
#         result[s] = 0
#         for _ in range(1, n):
#             for u, v, w in edges:
#                 if result[u] != sys.maxsize and result[u] + w < result[v]:
#                     result[v] = result[u] + w
#                 if result[v] != sys.maxsize and result[v] + w < result[u]:
#                     result[u] = result[v] + w

#     def findResultCity(self, n: int, spm: List[List[int]], distanceThreshold: int) -> int:
#         resultCity = -1
#         leastReachCount = sys.maxsize
#         for i in range(n):
#             countReach = sum(1 for j in range(n) if i != j and spm[i][j] <= distanceThreshold)
#             if countReach < leastReachCount or (countReach == leastReachCount and i > resultCity):
#                 leastReachCount = countReach
#                 resultCity = i
#         return resultCity

#     def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
#         spm = [[sys.maxsize] * n for _ in range(n)]
#         for i in range(n):
#             spm[i][i] = 0
        
#         for u, v, w in edges:
#             spm[u][v] = w
#             spm[v][u] = w
        
#         for i in range(n):
#             self.bellmanFord(n, edges, spm[i], i)

#         return self.findResultCity(n, spm, distanceThreshold)












# class Solution:
#     def dijkstra(self, n: int, graph: dict, result: List[int], s: int) -> None:
#         pq = [(0, s)]
#         result[s] = 0
#         while pq:
#             d, node = heapq.heappop(pq)
#             if d > result[node]:
#                 continue
#             for adjNode, dist in graph[node]:
#                 if d + dist < result[adjNode]:
#                     result[adjNode] = d + dist
#                     heapq.heappush(pq, (d + dist, adjNode))

#     def findResultCity(self, n: int, spm: List[List[int]], distanceThreshold: int) -> int:
#         resultCity = -1
#         leastReachCount = sys.maxsize
#         for i in range(n):
#             countReach = sum(1 for j in range(n) if i != j and spm[i][j] <= distanceThreshold)
#             if countReach < leastReachCount or (countReach == leastReachCount and i > resultCity):
#                 leastReachCount = countReach
#                 resultCity = i
#         return resultCity

#     def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
#         spm = [[sys.maxsize] * n for _ in range(n)]
#         for i in range(n):
#             spm[i][i] = 0
        
#         graph = {i: [] for i in range(n)}
#         for u, v, w in edges:
#             graph[u].append((v, w))
#             graph[v].append((u, w))
        
#         for i in range(n):
#             self.dijkstra(n, graph, spm[i], i)

#         return self.findResultCity(n, spm, distanceThreshold)