class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        n, m = len(grid), len(grid[0])
        dp = [[-1 for _ in range(m)] for _ in range(n)]
        q = deque()
        q.append([0, 0, health - grid[0][0]])
        dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        dp[0][0] = health - grid[0][0]
        
        while q:
            x, y, val = q.popleft()
            if x == n - 1 and y == m - 1:
                if val > 0:
                    return True
            for dir in dirs:
                newX, newY = x + dir[0], y + dir[1]
                if 0 <= newX < n and 0 <= newY < m:
                    newVal = val - grid[newX][newY]
                    if newVal > 0 and newVal > dp[newX][newY]:
                        q.append([newX, newY, newVal])
                        dp[newX][newY] = newVal
        
        return False