class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        directions = [(-1, 0), (1, 0), (0, 1), (0, -1)]
        
        def dfs(i, j, id):
            if i < 0 or i >= n or j < 0 or j >= n or grid[i][j] != 1:
                return 0
            grid[i][j] = id
            return 1 + sum(dfs(i + dx, j + dy, id) for dx, dy in directions)
        
        island_sizes = {}
        island_id = 2
        max_area = 0

        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    size = dfs(i, j, island_id)
                    island_sizes[island_id] = size
                    max_area = max(max_area, size)
                    island_id += 1

        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    adjacent_islands = set()
                    for dx, dy in directions:
                        x, y = i + dx, j + dy
                        if 0 <= x < n and 0 <= y < n and grid[x][y] > 1:
                            adjacent_islands.add(grid[x][y])
                    
                    new_size = 1 + sum(island_sizes[iid] for iid in adjacent_islands)
                    max_area = max(max_area, new_size)

        return max_area if max_area else n * n