class Solution:        
    def __init__(self):
        self.m = 0
        self.n = 0
        self.t = []
        self.colDir = [-1, 0, 1]
    
    def isSafe(self, i):
        return i >= 0 and i < self.n
    
    def solve(self, grid, row, c1, c2):
        if row >= self.m:
            return 0
        
        if self.t[row][c1][c2] != -1:
            return self.t[row][c1][c2]
        
        count = grid[row][c1]
        if c1 != c2:
            count += grid[row][c2]
        
        ans = 0
        for x in self.colDir:
            for y in self.colDir:
                c1_ = x + c1
                c2_ = y + c2
                if self.isSafe(c1_) and self.isSafe(c2_):
                    ans = max(ans, self.solve(grid, row + 1, c1_, c2_))
        
        self.t[row][c1][c2] = count + ans
        return self.t[row][c1][c2]
    
    def cherryPickup(self, grid: List[List[int]]) -> int:
        self.m = len(grid)
        self.n = len(grid[0])
        self.t = [[[-1 for _ in range(self.n)] for _ in range(self.n)] for _ in range(self.m)]
        return self.solve(grid, 0, 0, self.n - 1)