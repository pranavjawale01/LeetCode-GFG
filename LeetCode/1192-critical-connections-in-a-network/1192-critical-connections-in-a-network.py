class Solution:
    def __init__(self):
        self.bridges = []
        self.timer = 0

    def dfs(self, node, parent, visited, timein, lowtime, adj):
        visited[node] = 1
        timein[node] = self.timer
        lowtime[node] = self.timer
        self.timer += 1
        for it in adj[node]:
            if it == parent:
                continue
            if visited[it] == 0:
                self.dfs(it, node, visited, timein, lowtime, adj)
                lowtime[node] = min(lowtime[node], lowtime[it])
                if lowtime[it] > timein[node]:
                    self.bridges.append([node, it])
            else:
                lowtime[node] = min(lowtime[node], timein[it])
                
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        adj = [[] for _ in range(n)]
        for connection in connections:
            u, v = connection
            adj[u].append(v)
            adj[v].append(u)
        visited = [0] * n
        timein = [0] * n
        lowtime = [0] * n
        self.dfs(0, -1, visited, timein, lowtime, adj)
        return self.bridges