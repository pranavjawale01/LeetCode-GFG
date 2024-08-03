class Solution:
    def minFlips(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        ans = 0
        
        if n % 2 == 1 and m % 2 == 1:
            if grid[n // 2][m // 2] == 1:
                ans += 1
        
        shift = [0] * 3
        
        if n % 2 == 1:
            a, b = 0, m - 1
            while a < b:
                sum_val = grid[n // 2][a] + grid[n // 2][b]
                shift[sum_val] += 1
                a += 1
                b -= 1
        
        if m % 2 == 1:
            a, b = 0, n - 1
            while a < b:
                sum_val = grid[a][m // 2] + grid[b][m // 2]
                shift[sum_val] += 1
                a += 1
                b -= 1
        
        if shift[2] % 2 == 1:
            if shift[1] > 0:
                ans += shift[1]
            else:
                ans += 2
        else:
            ans += shift[1]
        
        for i in range(n // 2):
            for j in range(m // 2):
                a = grid[i][j]
                b = grid[n - 1 - i][j]
                c = grid[i][m - 1 - j]
                d = grid[n - 1 - i][m - 1 - j]
                sum_val = a + b + c + d
                if sum_val != 0 and sum_val != 4:
                    ans += min(sum_val, 4 - sum_val)
        
        return ans