class Solution:
    def __init__(self):
        self.cycleDetected = False

    def dfs(self, mp, u, vis, rec, st):
        vis[u] = True
        rec[u] = True
        for v in mp[u]:
            if rec[v]:
                self.cycleDetected = True
                return
            if not vis[v]:
                self.dfs(mp, v, vis, rec, st)
                if self.cycleDetected:
                    return
        st.append(u)
        rec[u] = False

    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        mp = defaultdict(list)
        for x in prerequisites:
            mp[x[1]].append(x[0])
        
        rec = [False] * numCourses
        vis = [False] * numCourses
        st = []

        for i in range(numCourses):
            if not vis[i]:
                self.dfs(mp, i, vis, rec, st)
                if self.cycleDetected:
                    return []
        
        return st[::-1]





# class Solution:
#     def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
#         mp = {i: [] for i in range(numCourses)}
#         indegree = [0] * numCourses
        
#         for x in prerequisites:
#             mp[x[1]].append(x[0])
#             indegree[x[0]] += 1
        
#         q = deque()
#         ans = []
#         count = 0
        
#         for i in range(numCourses):
#             if indegree[i] == 0:
#                 q.append(i)
#                 ans.append(i)
#                 count += 1
        
#         while q:
#             x = q.popleft()
#             for v in mp[x]:
#                 indegree[v] -= 1
#                 if indegree[v] == 0:
#                     q.append(v)
#                     ans.append(v)
#                     count += 1
        
#         if count == numCourses:
#             return ans
#         return []