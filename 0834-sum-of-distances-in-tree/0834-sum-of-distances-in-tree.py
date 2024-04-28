class Solution:
    def __init__(self):
        self.root_result = 0
        self.count = []
        self.N = 0

    def dfs_root(self, adj, curr_node, prev_node, curr_depth):
        total_count = 1
        self.root_result += curr_depth
        for child in adj[curr_node]:
            if child == prev_node:
                continue
            total_count += self.dfs_root(adj, child, curr_node, curr_depth + 1)
        self.count[curr_node] = total_count
        return total_count

    def dfs(self, adj, parent_node, prev_node, result):
        for child in adj[parent_node]:
            if child == prev_node:
                continue
            result[child] = result[parent_node] - self.count[child] + (self.N - self.count[child])
            self.dfs(adj, child, parent_node, result)

    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        adj = defaultdict(list)
        self.N = n
        self.count = [0] * n
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        self.root_result = 0
        self.dfs_root(adj, 0, -1, 0)

        result = [0] * n
        result[0] = self.root_result
        self.dfs(adj, 0, -1, result)

        return result        