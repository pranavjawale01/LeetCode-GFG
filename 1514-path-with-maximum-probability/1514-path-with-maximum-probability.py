class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        adj = defaultdict(list)
        result = [0.0] * n
        
        for i, (u, v) in enumerate(edges):
            prob = succProb[i]
            adj[u].append((v, prob))
            adj[v].append((u, prob))
        
        pq = []
        result[start_node] = 1.0
        heappush(pq, (-1.0, start_node))
        
        while pq:
            curr_prob, curr_node = heappop(pq)
            curr_prob = -curr_prob
            
            if curr_node == end_node:
                return curr_prob
            
            for neighbor, edge_prob in adj[curr_node]:
                if result[neighbor] < curr_prob * edge_prob:
                    result[neighbor] = curr_prob * edge_prob
                    heappush(pq, (-result[neighbor], neighbor))
        
        return 0.0