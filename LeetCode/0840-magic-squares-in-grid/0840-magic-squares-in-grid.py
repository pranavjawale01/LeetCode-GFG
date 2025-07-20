class Solution:
    def isMagicSquare(self, grid, r, c):
        st = set()
        sum_val = 15
        
        for i in range(r, r + 3):
            for j in range(c, c + 3):
                if grid[i][j] < 1 or grid[i][j] > 9 or grid[i][j] in st:
                    return False
                st.add(grid[i][j])

        if grid[r][c] + grid[r][c + 1] + grid[r][c + 2] != sum_val:
            return False
        if grid[r + 1][c] + grid[r + 1][c + 1] + grid[r + 1][c + 2] != sum_val:
            return False
        if grid[r + 2][c] + grid[r + 2][c + 1] + grid[r + 2][c + 2] != sum_val:
            return False
        
        if grid[r][c] + grid[r + 1][c] + grid[r + 2][c] != sum_val:
            return False
        if grid[r][c + 1] + grid[r + 1][c + 1] + grid[r + 2][c + 1] != sum_val:
            return False
        if grid[r][c + 2] + grid[r + 1][c + 2] + grid[r + 2][c + 2] != sum_val:
            return False
        
        if grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != sum_val:
            return False
        if grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != sum_val:
            return False
        
        return True

    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        if row < 3 or col < 3:
            return 0
        count = 0
        for i in range(row - 2):
            for j in range(col - 2):
                if self.isMagicSquare(grid, i, j):
                    count += 1
        return count