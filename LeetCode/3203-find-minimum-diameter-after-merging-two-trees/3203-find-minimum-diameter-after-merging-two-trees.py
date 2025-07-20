class Solution:
    def buildGraph(self, edges):
        graph = defaultdict(list)
        for x in edges:
            graph[x[0]].append(x[1])
            graph[x[1]].append(x[0])
        return graph
    
    def findFarthest(self, node, par, dist, graph, res):
        if dist > res[0]:
            res[0] = dist
            res[1] = node
        for x in graph.get(node, []):
            if x != par:
                self.findFarthest(x, node, dist + 1, graph, res)
        return res

    def minimumDiameterAfterMerge(self, edges1: List[List[int]], edges2: List[List[int]]) -> int:
        graph1 = self.buildGraph(edges1)
        graph2 = self.buildGraph(edges2)
        
        res1 = [float('-inf'), -1]
        self.findFarthest(0, -1, 0, graph1, res1)
        res2 = [float('-inf'), -1]
        self.findFarthest(res1[1], -1, 0, graph1, res2)
        d1 = res2[0]

        res1 = [float('-inf'), -1]
        self.findFarthest(0, -1, 0, graph2, res1)
        res2 = [float('-inf'), -1]
        self.findFarthest(res1[1], -1, 0, graph2, res2)
        d2 = res2[0]

        return max(d1, max(d2, ((d1 + 1) // 2) + ((d2 + 1) // 2) + 1))