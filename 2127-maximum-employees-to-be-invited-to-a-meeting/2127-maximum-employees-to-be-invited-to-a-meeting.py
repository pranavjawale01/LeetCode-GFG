class Solution:
    def bfs(self, start, graph, visited):
        queue = deque([(start, 0)])
        max_dist = 0

        while queue:
            curr_node, dist = queue.popleft()
            for neighbor in graph[curr_node]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    queue.append((neighbor, dist + 1))
                    max_dist = max(max_dist, dist + 1)
        return max_dist
        
    def maximumInvitations(self, favorite: List[int]) -> int:
        n = len(favorite)
        graph = defaultdict(list)

        # Build the reverse graph
        for i in range(n):
            graph[favorite[i]].append(i)

        longest_cycle_length = 0
        happy_couple_count = 0
        visited = [False] * n

        for i in range(n):
            if not visited[i]:
                seen = {}
                curr_node = i
                steps = 0

                while not visited[curr_node]:
                    visited[curr_node] = True
                    seen[curr_node] = steps
                    next_node = favorite[curr_node]
                    steps += 1

                    if next_node in seen:
                        cycle_length = steps - seen[next_node]
                        longest_cycle_length = max(longest_cycle_length, cycle_length)

                        if cycle_length == 2:
                            temp_visited = [False] * n
                            temp_visited[curr_node] = True
                            temp_visited[next_node] = True
                            happy_couple_count += 2 + self.bfs(curr_node, graph, temp_visited) + self.bfs(next_node, graph, temp_visited)
                        break
                    curr_node = next_node

        return max(happy_couple_count, longest_cycle_length)