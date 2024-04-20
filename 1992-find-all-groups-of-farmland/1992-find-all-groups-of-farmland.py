class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        row, col = len(land), len(land[0])
        ans = []

        def dfs(land, i, j, row, col, max_coords):
            if i < 0 or j < 0 or i >= row or j >= col or land[i][j] == 0:
                max_coords[0] = max(i-1, max_coords[0])
                max_coords[1] = max(j-1, max_coords[1])
                return
            land[i][j] = 0
            max_coords[0] = max(i, max_coords[0])
            max_coords[1] = max(j, max_coords[1])
            dfs(land, i+1, j, row, col, max_coords)
            dfs(land, i-1, j, row, col, max_coords)
            dfs(land, i, j+1, row, col, max_coords)
            dfs(land, i, j-1, row, col, max_coords)

        for i in range(row):
            for j in range(col):
                if land[i][j] == 1:
                    max_coords = [i, j]
                    dfs(land, i, j, row, col, max_coords)
                    ans.append([i, j, max_coords[0], max_coords[1]])

        return ans