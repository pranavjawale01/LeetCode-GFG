class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        mp = defaultdict(list)
        for u, v in edges:
            mp[u].append(v)
            mp[v].append(u)
        visited = [False] * n
        q = deque()
        q.append(source)
        visited[source] = True
        while q:
            node = q.popleft()
            if node == destination:
                return True
            for v in mp[node]:
                if not visited[v]:
                    q.append(v)
                    visited[v] = True
        return False

# class Solution:
#     def check(self, mp, s, d, visited) -> bool:
#         if s == d:
#             return True
#         if visited[s]:
#             return False
#         visited[s] = True
#         for node in mp[s]:
#             if self.check(mp, node, d, visited):
#                 return True
#         return False

#     def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
#         mp = defaultdict(list)
#         for u, v in edges:
#             mp[u].append(v)
#             mp[v].append(u)
#         visited = [False] * n
#         return self.check(mp, source, destination, visited)