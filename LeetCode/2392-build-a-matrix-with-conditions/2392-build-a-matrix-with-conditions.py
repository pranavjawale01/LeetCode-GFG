class Solution:
    def topoSort(self, edges, n):
        adj = defaultdict(list)
        indegree = [0] * (n + 1)
        order = []
        
        for u, v in edges:
            adj[u].append(v)
            indegree[v] += 1

        queue = deque()
        count = 0
        for i in range(1, n + 1):
            if indegree[i] == 0:
                queue.append(i)
                count += 1

        while queue:
            u = queue.popleft()
            order.append(u)
            
            for v in adj[u]:
                indegree[v] -= 1
                if indegree[v] == 0:
                    queue.append(v)
                    count += 1

        if count != n:
            return []

        return order

    def buildMatrix(self, k: int, rowConditions: List[List[int]], colConditions: List[List[int]]) -> List[List[int]]:
        orderRows = self.topoSort(rowConditions, k)
        orderColumns = self.topoSort(colConditions, k)

        if not orderRows or not orderColumns:
            return []

        matrix = [[0] * k for _ in range(k)]
        positionMap = {val: idx for idx, val in enumerate(orderColumns)}

        for i in range(k):
            element = orderRows[i]
            if element in positionMap:
                matrix[i][positionMap[element]] = element

        return matrix






# class Solution:
#     def dfs(self, node: int, adj: Dict[int, List[int]], vis: List[int], stack: List[int], hasCycle: List[bool]) -> None:
#         vis[node] = 1
#         for x in adj[node]:
#             if vis[x] == 0:
#                 self.dfs(x, adj, vis, stack, hasCycle)
#                 if hasCycle[0]:
#                     return
#             elif vis[x] == 1:
#                 hasCycle[0] = True
#                 return
#         vis[node] = 2
#         stack.append(node)
    
#     def topoSort(self, edges: List[List[int]], n: int) -> List[int]:
#         adj = defaultdict(list)
#         stack = []
#         vis = [0] * (n + 1)
#         hasCycle = [False]
        
#         for u, v in edges:
#             adj[u].append(v)
        
#         for i in range(1, n + 1):
#             if vis[i] == 0:
#                 self.dfs(i, adj, vis, stack, hasCycle)
#                 if hasCycle[0]:
#                     return []
        
#         return stack[::-1]
    
#     def buildMatrix(self, k: int, rowConditions: List[List[int]], colConditions: List[List[int]]) -> List[List[int]]:
#         orderRows = self.topoSort(rowConditions, k)
#         orderCols = self.topoSort(colConditions, k)
        
#         if not orderRows or not orderCols:
#             return []
        
#         matrix = [[0] * k for _ in range(k)]
#         rowPos = {num: i for i, num in enumerate(orderRows)}
#         colPos = {num: i for i, num in enumerate(orderCols)}
        
#         for i in range(1, k + 1):
#             r = rowPos[i]
#             c = colPos[i]
#             matrix[r][c] = i
        
#         return matrix