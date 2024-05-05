class Solution:
    def __init__(self):
        self.ans = []

    def solve(self, graph, temp, n, source):
        if source == n - 1:
            temp.append(source)
            self.ans.append(temp[:])
            temp.pop()
            return
        
        temp.append(source)
        for x in graph[source]:
            self.solve(graph, temp, n, x)
        temp.pop()

    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        n = len(graph)
        temp = []
        self.solve(graph, temp, n, 0)
        return self.ans