class Solution:
    def __init__(self):
        self.mp = {}

    def solve(self, s: int, e: int, vis: List[bool]) -> bool:
        vis[s] = True
        if s == e:
            return True
        reachable = False
        for x in self.mp.get(s, []):
            if not vis[x]:
                reachable |= self.solve(x, e, vis)
        return reachable

    def help(self, numCourses: int, check: List[List[bool]]) -> None:
        for i in range(numCourses):
            for j in range(numCourses):
                if i != j:
                    vis = [False] * numCourses
                    if self.solve(i, j, vis):
                        check[i][j] = True

    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        for u, v in prerequisites:
            if u not in self.mp:
                self.mp[u] = []
            self.mp[u].append(v)

        check = [[False] * numCourses for _ in range(numCourses)]
        self.help(numCourses, check)

        ans = []
        for u, v in queries:
            ans.append(check[u][v])
        return ans





# class Solution:
#     def solve(self, mp: dict, s: int, e: int, vis: List[bool]) -> bool:
#         vis[s] = True
#         if s == e:
#             return True
#         reachable = False
#         for x in mp.get(s, []):
#             if not vis[x]:
#                 reachable |= self.solve(mp, x, e, vis)
#         return reachable

#     def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
#         mp = {}
#         for u, v in prerequisites:
#             if u not in mp:
#                 mp[u] = []
#             mp[u].append(v)
        
#         ans = []
#         for u, v in queries:
#             vis = [False] * numCourses
#             ans.append(self.solve(mp, u, v, vis))
#         return ans