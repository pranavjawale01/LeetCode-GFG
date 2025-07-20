class Solution:
    def mostProfitablePath(self, edges: List[List[int]], bob: int, amount: List[int]) -> int:
        adj = defaultdict(list)
        bob_map = {}

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        def dfs_bob(curr, time, visited):
            visited[curr] = True
            bob_map[curr] = time

            if curr == 0:
                return True

            for neighbor in adj[curr]:
                if not visited[neighbor]:
                    if dfs_bob(neighbor, time + 1, visited):
                        return True

            del bob_map[curr] 
            return False

        n = len(amount)
        visited = [False] * n
        dfs_bob(bob, 0, visited)

        queue = deque([(0, 0, 0)])
        visited = [False] * n
        alice_income = float('-inf')

        while queue:
            curr, time, income = queue.popleft()

            if curr not in bob_map or bob_map[curr] > time:
                income += amount[curr]
            elif bob_map[curr] == time:
                income += amount[curr] // 2

            if len(adj[curr]) == 1 and curr != 0:
                alice_income = max(alice_income, income)

            for neighbor in adj[curr]:
                if not visited[neighbor]:
                    queue.append((neighbor, time + 1, income))

            visited[curr] = True

        return alice_income