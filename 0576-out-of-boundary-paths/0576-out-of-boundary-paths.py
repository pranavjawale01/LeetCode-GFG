class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        
        direction = [[0,1], [1,0], [0,-1], [-1,0]]
        MOD = 10**9 + 7
        memory = [[[-1 for _ in range(maxMove + 1)] for _ in range(n)] for _ in range(m)]
        
        def solve(maxMove: int, startRow: int, startColumn: int) -> int:
            if startRow < 0 or startRow >= m or startColumn < 0 or startColumn >= n:
                return 1
            if maxMove <= 0:
                return 0
            if memory[startRow][startColumn][maxMove] != -1:
                return memory[startRow][startColumn][maxMove]
            
            result = 0
            for i in range(len(direction)):
                result = (result + solve(maxMove - 1, startRow + direction[i][0], startColumn + direction[i][1])) % MOD
            
            memory[startRow][startColumn][maxMove] = result
            return result
            
        return solve(maxMove, startRow, startColumn)