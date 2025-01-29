class DSU:
    def __init__(self, n):
        self.parent = list(range(n + 1))
        self.rank = [0] * (n + 1)

    def find(self, x):
        if x != self.parent[x]:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        xpar, ypar = self.find(x), self.find(y)
        if xpar == ypar:
            return
        if self.rank[xpar] > self.rank[ypar]:
            self.parent[ypar] = xpar
        elif self.rank[ypar] > self.rank[xpar]:
            self.parent[xpar] = ypar
        else:
            self.parent[ypar] = xpar
            self.rank[xpar] += 1
            
            
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        dsu = DSU(len(edges))
        for u, v in edges:
            if dsu.find(u) == dsu.find(v):
                return [u, v]
            dsu.union(u, v)
        return []




# class Solution:
#     def bfs(self, mp, u, v, vis):
#         q = deque([u])
#         vis[u] = True
#         while q:
#             curr = q.popleft()
#             if curr == v:
#                 return True
#             for x in mp[curr]:
#                 if not vis.get(x, False):
#                     vis[x] = True
#                     q.append(x)
#         return False

#     def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
#         mp = defaultdict(list)
#         for u, v in edges:
#             vis = {}
#             if u in mp and v in mp and self.bfs(mp, u, v, vis):
#                 return [u, v]
#             mp[u].append(v)
#             mp[v].append(u)
#         return []



# # class Solution:
# #     def dfs(self, mp, u, v, vis):
# #         if u == v:
# #             return True
# #         vis.add(u)
# #         for x in mp[u]:
# #             if x in vis:
# #                 continue
# #             if self.dfs(mp, x, v, vis):
# #                 return True
# #         return False

# #     def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
# #         mp = defaultdict(list)
# #         for u, v in edges:
# #             vis = set()
# #             if u in mp and v in mp and self.dfs(mp, u, v, vis):
# #                 return [u, v]
# #             mp[u].append(v)
# #             mp[v].append(u)
# #         return []