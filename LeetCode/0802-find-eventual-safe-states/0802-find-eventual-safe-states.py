class Solution:
    def isCycleDFS(self, graph: List[List[int]], u: int, visited: List[bool], inRecursion: List[bool]) -> bool:
        visited[u] = True
        inRecursion[u] = True

        for v in graph[u]:
            if not visited[v] and self.isCycleDFS(graph, v, visited, inRecursion):
                return True
            elif inRecursion[v]:
                return True

        inRecursion[u] = False
        return False

    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        n = len(graph)
        visited = [False] * n
        inRecursion = [False] * n
        ans = []

        for i in range(n):
            if not visited[i]:
                self.isCycleDFS(graph, i, visited, inRecursion)
        
        for i in range(n):
            if not inRecursion[i]:
                ans.append(i)

        return ans