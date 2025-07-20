class neighborSum:

    def __init__(self, grid: List[List[int]]):
        self.arr = grid
        self.row = len(grid)
        self.col = len(grid[0])
        self.mp = {}
        for i in range(self.row):
            for j in range(self.col):
                self.mp[grid[i][j]] = (i, j)

    def adjacentSum(self, value: int) -> int:
        if value not in self.mp:
            return 0
        x, y = self.mp[value]
        sum = 0
        dirs = [(-1, 0), (0, -1), (1, 0), (0, 1)]
        for d in dirs:
            a, b = d[0] + x, d[1] + y
            if 0 <= a < self.row and 0 <= b < self.col:
                sum += self.arr[a][b]
        return sum

    def diagonalSum(self, value: int) -> int:
        if value not in self.mp:
            return 0
        x, y = self.mp[value]
        sum = 0
        dirs = [(-1, -1), (1, -1), (1, 1), (-1, 1)]
        for d in dirs:
            a, b = d[0] + x, d[1] + y
            if 0 <= a < self.row and 0 <= b < self.col:
                sum += self.arr[a][b]
        return sum


# Your neighborSum object will be instantiated and called as such:
# obj = neighborSum(grid)
# param_1 = obj.adjacentSum(value)
# param_2 = obj.diagonalSum(value)