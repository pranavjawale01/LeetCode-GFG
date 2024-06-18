class Solution:
    def binarySearch(self, mat: List[int], n: int) -> int:
        low = 0
        high = n - 1
        while low <= high:
            mid = low + (high - low) // 2
            if mat[mid] < 0:
                high = mid - 1
            else:
                low = mid + 1
        return n - low

    def countNegatives(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        totalCount = 0
        for i in range(row):
            totalCount += self.binarySearch(grid[i], col)
        return totalCount