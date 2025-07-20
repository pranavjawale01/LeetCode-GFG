class Solution:
    def DFS(self, adj, i, visited):
        visited[i] = True
        for v in adj[i]:
            if not visited[v]:
                self.DFS(adj, v, visited)

    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        count = 0
        n = len(isConnected)
        visited = [False] * n
        adj = {}
        for i in range(n):
            adj[i] = []
            for j in range(n):
                if isConnected[i][j] == 1:
                    if j not in adj:
                        adj[j] = []
                    adj[i].append(j)
                    adj[j].append(i)
        for i in range(n):
            if not visited[i]:
                self.DFS(adj, i, visited)
                count += 1
        return count