class Solution:
    def isBipartite(self, graph: dict, node: int, colors: List[int]) -> bool:
        queue = deque([node])
        colors[node] = 0
        
        while queue:
            curr = queue.popleft()
            for neighbor in graph[curr]:
                if colors[neighbor] == colors[curr]:
                    return False
                if colors[neighbor] == -1:
                    colors[neighbor] = 1 - colors[curr]
                    queue.append(neighbor)
        return True
    
    def bfs_max_level(self, graph: dict, start: int) -> int:
        queue = deque([start])
        visited = set([start])
        level = 0

        while queue:
            for _ in range(len(queue)):
                node = queue.popleft()
                for neighbor in graph[node]:
                    if neighbor not in visited:
                        visited.add(neighbor)
                        queue.append(neighbor)
            level += 1

        return level

    def magnificentSets(self, n: int, edges: List[List[int]]) -> int:
        graph = defaultdict(list)
        for u, v in edges:
            graph[u - 1].append(v - 1)
            graph[v - 1].append(u - 1)

        colors = [-1] * n
        for node in range(n):
            if colors[node] == -1:
                if not self.isBipartite(graph, node, colors):
                    return -1

        visited = set()
        max_groups = 0

        for node in range(n):
            if node not in visited:
                component = []
                queue = deque([node])
                visited.add(node)

                while queue:
                    curr = queue.popleft()
                    component.append(curr)
                    for neighbor in graph[curr]:
                        if neighbor not in visited:
                            visited.add(neighbor)
                            queue.append(neighbor)

                max_level = 0
                for start in component:
                    max_level = max(max_level, self.bfs_max_level(graph, start))

                max_groups += max_level

        return max_groups