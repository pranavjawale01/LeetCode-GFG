class Solution:
    def dfs(self, node: int, adj: List[List[int]], vis: List[bool]) -> None:
        vis[node] = True
        for x in adj[node]:
            if not vis[x]:
                self.dfs(x, adj, vis)

    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(n)]
        
        for u, v in invocations:
            adj[u].append(v)

        vis = [False] * n
        
        self.dfs(k, adj, vis)

        suspicious = True
        for i in range(n):
            if not vis[i]:
                for x in adj[i]:
                    if vis[x]:
                        suspicious = False

        ans = []
        if suspicious:
            for i in range(n):
                if not vis[i]:
                    ans.append(i)
        else:
            ans = list(range(n))
        
        return ans







# TLE
# class Solution:
#     def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
#         bug = set()
#         bug.add(k)
#         flag = True
        
#         while flag:
#             flag = False
#             for a, b in invocations:
#                 if a in bug and b not in bug:
#                     bug.add(b)
#                     flag = True
        
#         for a, b in invocations:
#             if a not in bug and b in bug:
#                 return list(range(n))
        
#         return [i for i in range(n) if i not in bug]