class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indegree = [0] * numCourses
        mp = defaultdict(list)

        for a, b in prerequisites:
            mp[b].append(a)
            indegree[a] += 1
        
        q = deque()
        count = 0

        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)
                count += 1
        
        while q:
            curr = q.popleft()
            for x in mp[curr]:
                indegree[x] -= 1
                if indegree[x] == 0:
                    q.append(x)
                    count += 1
        
        return count == numCourses