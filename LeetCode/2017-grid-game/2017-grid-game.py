class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        n = len(grid[0])
        firstRowSum = sum(grid[0])
        secondRowSum = 0
        minRob2Sum = float('inf')

        for i in range(n):
            firstRowSum -= grid[0][i]
            minRob2Sum = min(minRob2Sum, max(firstRowSum, secondRowSum))
            secondRowSum += grid[1][i]

        return minRob2Sum