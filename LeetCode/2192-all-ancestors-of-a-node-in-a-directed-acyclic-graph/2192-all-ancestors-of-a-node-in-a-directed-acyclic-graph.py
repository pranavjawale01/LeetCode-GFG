class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        adj = defaultdict(list)
        indegree = [0] * n
        for u, v in edges:
            adj[u].append(v)
            indegree[v] += 1
            
        q = deque([i for i in range(n) if indegree[i] == 0])
        ancestors = [set() for _ in range(n)]
        
        while q:
            curr = q.popleft()
            for neighbor in adj[curr]:
                ancestors[neighbor].add(curr)
                ancestors[neighbor].update(ancestors[curr])
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    q.append(neighbor)
        
        return [sorted(list(ancestor_set)) for ancestor_set in ancestors]






# class Solution:
#     def solve(self, mp, node, temp, visited):
#         if visited[node]:
#             return
#         visited[node] = True
        
#         for ancestor in mp[node]:
#             if not visited[ancestor]:
#                 temp.append(ancestor)
#                 self.solve(mp, ancestor, temp, visited)

#     def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
#         mp = defaultdict(list)
#         ans = [[] for _ in range(n)]
        
#         for edge in edges:
#             mp[edge[1]].append(edge[0])

#         for i in range(n):
#             temp = []
#             visited = [False] * n
#             self.solve(mp, i, temp, visited)
#             temp.sort()
#             ans[i] = temp

#         return ans