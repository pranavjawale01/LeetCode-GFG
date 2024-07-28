class Solution:
    def secondMinimum(self, n: int, edges: List[List[int]], time: int, change: int) -> int:
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        min1 = [float('inf')] * (n + 1)
        min2 = [float('inf')] * (n + 1)

        queue = deque([(1, 1)])
        min1[1] = 0

        while queue:
            node, freq = queue.popleft()
            
            timePassed = min1[node] if freq == 1 else min2[node]
            
            if node == n and min2[n] != float('inf'):
                return min2[n]
            
            div = timePassed // change
            if div % 2 == 1:
                timePassed = change * (div + 1)
            
            for neighbor in graph[node]:
                if min1[neighbor] == float('inf'):
                    min1[neighbor] = timePassed + time
                    queue.append((neighbor, 1))
                elif min2[neighbor] == float('inf') and min1[neighbor] != timePassed + time:
                    min2[neighbor] = timePassed + time
                    queue.append((neighbor, 2))
        
        return -1








# class Solution:
#     def secondMinimum(self, n: int, edges: List[List[int]], time: int, change: int) -> int:
#         graph = defaultdict(list)
#         for u, v in edges:
#             graph[u].append(v)
#             graph[v].append(u)

#         min1 = [float('inf')] * (n + 1)
#         min2 = [float('inf')] * (n + 1)

#         pq = [(0, 1)]
#         min1[1] = 0

#         while pq:
#             timePassed, node = heapq.heappop(pq)
            
#             if node == n and min2[n] != float('inf'):
#                 return min2[n]
            
#             div = timePassed // change
#             if div % 2 == 1:
#                 timePassed = change * (div + 1)

#             for neighbor in graph[node]:
#                 if min1[neighbor] > timePassed + time:
#                     min2[neighbor] = min1[neighbor]
#                     min1[neighbor] = timePassed + time
#                     heapq.heappush(pq, (timePassed + time, neighbor))
#                 elif min2[neighbor] > timePassed + time and min1[neighbor] != timePassed + time:
#                     min2[neighbor] = timePassed + time
#                     heapq.heappush(pq, (timePassed + time, neighbor))

#         return -1