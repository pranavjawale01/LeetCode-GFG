class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        graph = defaultdict(deque)
        indegree = defaultdict(int)
        outdegree = defaultdict(int)
        
        for u, v in pairs:
            graph[u].append(v)
            outdegree[u] += 1
            indegree[v] += 1
        
        start = -1
        for node in graph:
            if outdegree[node] - indegree[node] == 1:
                start = node
                break
        if start == -1:
            start = pairs[0][0]
        
        path = []
        stack = [start]
        
        while stack:
            curr = stack[-1]
            if graph[curr]:
                next_node = graph[curr].pop()
                stack.append(next_node)
            else:
                path.append(stack.pop())
        
        path.reverse()
        result = [[path[i], path[i + 1]] for i in range(len(path) - 1)]
        return result