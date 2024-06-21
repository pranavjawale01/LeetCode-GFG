class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        color = [0] * n
        for node in range(n):
            if color[node] != 0:
                continue
            q = deque()
            q.append(node)
            color[node] = 1
            while q:
                cur = q.popleft()

                for ne in graph[cur]:
                    if color[ne] == 0:
                        color[ne] = -color[cur]
                        q.append(ne)
                    elif color[ne] != -color[cur]:
                        return False
        
        return True



# class Solution:
#     def dfs(self, graph: List[List[int]], color, node, col) -> bool:
#         if color[node] != 0:
#             return color[node] == col
#         color[node] = col
#         for ne in graph[node]:
#             if not self.dfs(graph, color, ne, -col):
#                 return False
#         return True

#     def isBipartite(self, graph: List[List[int]]) -> bool:
#         n = len(graph)
#         color = [0] * n
#         for i in range(n):
#             if color[i] == 0 and not self.dfs(graph, color, i, 1):
#                 return False
#         return True