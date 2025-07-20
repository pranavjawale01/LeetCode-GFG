class Solution:
    def bfs(self, mp, start, k, size):
        vis = [False] * size
        q = deque([start])
        vis[start] = True
        cnt = 0
        dist = 0
        while q and dist <= k:
            len_q = len(q)
            for _ in range(len_q):
                node = q.popleft()
                cnt += 1
                for x in mp[node]:
                    if not vis[x]:
                        vis[x] = True
                        q.append(x)
            dist += 1
        return cnt

    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]], k: int) -> List[int]:
        n = len(edges1) + 1
        m = len(edges2) + 1
        mp1 = defaultdict(list)
        mp2 = defaultdict(list)
        
        for x in edges1:
            mp1[x[0]].append(x[1])
            mp1[x[1]].append(x[0])
        
        for x in edges2:
            mp2[x[0]].append(x[1])
            mp2[x[1]].append(x[0])

        count = [0] * n
        for i in range(n):
            count[i] = self.bfs(mp1, i, k, n)

        maxCountNode = 0
        for i in range(m):
            maxCountNode = max(maxCountNode, self.bfs(mp2, i, k - 1, m))

        ans = [0] * n
        for i in range(n):
            ans[i] = count[i] + maxCountNode

        return ans