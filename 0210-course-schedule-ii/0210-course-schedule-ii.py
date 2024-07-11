class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        mp = {i: [] for i in range(numCourses)}
        indegree = [0] * numCourses
        
        for x in prerequisites:
            mp[x[1]].append(x[0])
            indegree[x[0]] += 1
        
        q = deque()
        ans = []
        count = 0
        
        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)
                ans.append(i)
                count += 1
        
        while q:
            x = q.popleft()
            for v in mp[x]:
                indegree[v] -= 1
                if indegree[v] == 0:
                    q.append(v)
                    ans.append(v)
                    count += 1
        
        if count == numCourses:
            return ans
        return []