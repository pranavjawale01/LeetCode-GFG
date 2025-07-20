class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(n)]
        for it in redEdges:
            adj[it[0]].append((it[1], 0))
        for it in blueEdges:
            adj[it[0]].append((it[1], 1))
        ans = [-1] * n
        visited = [[False] * 2 for _ in range(n)]
        q = deque([(0, 0, -1)]) # node, steps, color
        visited[0][0] = True
        visited[0][1] = True
        ans[0] = 0
        while q:
            node, steps, preColor = q.popleft()
            for neighbor, color in adj[node]:
                if not visited[neighbor][color] and color != preColor:
                    visited[neighbor][color] = True
                    q.append((neighbor, steps + 1, color))
                    if ans[neighbor] == -1:
                        ans[neighbor] = steps + 1
        return ans