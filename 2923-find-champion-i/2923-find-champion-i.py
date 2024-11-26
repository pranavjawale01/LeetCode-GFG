class Solution:
    def findChampion(self, grid: List[List[int]]) -> int:
        mp = {}
        n = len(grid)
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    mp[i] = mp.get(i, 0) + 1
                else:
                    mp[j] = mp.get(j, 0) + 1
        team = -1
        freq = 0
        for k, v in mp.items():
            if v > freq:
                freq = v
                team = k
        return team