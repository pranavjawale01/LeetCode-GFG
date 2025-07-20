class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        result = []
        if n == 1:
            return [0]
        
        adj = defaultdict(set)
        degree = [0] * n
        
        for u, v in edges:
            adj[u].add(v)
            adj[v].add(u)
            degree[u] += 1
            degree[v] += 1
        
        leaves = deque()
        for i in range(n):
            if degree[i] == 1:
                leaves.append(i)
        
        while n > 2:
            size = len(leaves)
            n -= size
            for _ in range(size):
                leaf = leaves.popleft()
                for neighbor in adj[leaf]:
                    degree[neighbor] -= 1
                    if degree[neighbor] == 1:
                        leaves.append(neighbor)
        
        return list(leaves)