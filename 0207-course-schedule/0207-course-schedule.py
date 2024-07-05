class Solution:
    def isCyclic(self, mp, v, vis, rec):
        if rec[v]:
            return True
        if vis[v]:
            return False
        vis[v] = True
        rec[v] = True
        for x in mp[v]:
            if self.isCyclic(mp, x, vis, rec):
                return True
        rec[v] = False
        return False
        
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        mp = defaultdict(list)
        vis = [False] * numCourses
        rec = [False] * numCourses
        
        for x in prerequisites:
            mp[x[1]].append(x[0])
        
        for i in range(numCourses):
            if not vis[i] and self.isCyclic(mp, i, vis, rec):
                return False
        
        return True






# class Solution:
#     def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
#         indegree = [0] * numCourses
#         mp = defaultdict(list)

#         for a, b in prerequisites:
#             mp[b].append(a)
#             indegree[a] += 1
        
#         q = deque()
#         count = 0

#         for i in range(numCourses):
#             if indegree[i] == 0:
#                 q.append(i)
#                 count += 1
        
#         while q:
#             curr = q.popleft()
#             for x in mp[curr]:
#                 indegree[x] -= 1
#                 if indegree[x] == 0:
#                     q.append(x)
#                     count += 1
        
#         return count == numCourses