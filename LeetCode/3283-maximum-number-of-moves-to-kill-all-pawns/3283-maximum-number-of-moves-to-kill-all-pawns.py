class Solution:
    def __init__(self):
        self.dirs = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]
    
    def bfs(self, x: int, y: int, idx: int, minDist: List[List[int]], pos: List[List[int]]):
        N = 50
        dist = [[-1] * N for _ in range(N)]
        queue = deque([(x, y)])
        dist[x][y] = 0

        while queue:
            currX, currY = queue.popleft()
            for dx, dy in self.dirs:
                newX, newY = currX + dx, currY + dy
                if 0 <= newX < N and 0 <= newY < N and dist[newX][newY] == -1:
                    dist[newX][newY] = dist[currX][currY] + 1
                    queue.append((newX, newY))
        
        for i in range(len(pos)):
            x_, y_ = pos[i]
            minDist[idx][i] = dist[x_][y_]
    
    def solve(self, minDist: List[List[int]], idx: int, mask: int, n: int, alice: bool, dp: List[List[List[int]]]) -> int:
        if mask == 0:
            return 0
        if dp[idx][mask][1 if alice else 0] != -1:
            return dp[idx][mask][1 if alice else 0]
        
        result = float('-inf') if alice else float('inf')
        for i in range(1, n):
            if mask & (1 << (i - 1)):
                moves = minDist[idx][i]
                if alice:
                    result = max(result, moves + self.solve(minDist, i, mask ^ (1 << (i - 1)), n, not alice, dp))
                else:
                    result = min(result, moves + self.solve(minDist, i, mask ^ (1 << (i - 1)), n, not alice, dp))
        
        dp[idx][mask][1 if alice else 0] = result
        return result

    def maxMoves(self, kx: int, ky: int, positions: List[List[int]]) -> int:
        n = len(positions)
        pos = [[kx, ky]] + positions
        
        minDist = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(len(pos)):
            x, y = pos[i]
            self.bfs(x, y, i, minDist, pos)
        
        dp = [[[-1] * 2 for _ in range(1 << n)] for _ in range(n + 1)]
        alice = True
        return self.solve(minDist, 0, (1 << n) - 1, n + 1, alice, dp)