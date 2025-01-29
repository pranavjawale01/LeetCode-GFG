class Solution:
    def bfs(self, mp, u, v, vis):
        q = deque([u])
        vis[u] = True
        while q:
            curr = q.popleft()
            if curr == v:
                return True
            for x in mp[curr]:
                if not vis.get(x, False):
                    vis[x] = True
                    q.append(x)
        return False

    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        mp = defaultdict(list)
        for u, v in edges:
            vis = {}
            if u in mp and v in mp and self.bfs(mp, u, v, vis):
                return [u, v]
            mp[u].append(v)
            mp[v].append(u)
        return []



# class Solution:
#     def dfs(self, mp, u, v, vis):
#         if u == v:
#             return True
#         vis.add(u)
#         for x in mp[u]:
#             if x in vis:
#                 continue
#             if self.dfs(mp, x, v, vis):
#                 return True
#         return False

#     def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
#         mp = defaultdict(list)
#         for u, v in edges:
#             vis = set()
#             if u in mp and v in mp and self.dfs(mp, u, v, vis):
#                 return [u, v]
#             mp[u].append(v)
#             mp[v].append(u)
#         return []