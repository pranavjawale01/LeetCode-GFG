class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False
        
        n = len(matrix)
        m = len(matrix[0])
        
        row = 0
        while row < n and target > matrix[row][m - 1]:
            row += 1
        
        if row == n:
            return False
        
        low, high = 0, m - 1
        while low <= high:
            mid = low + (high - low) // 2
            if matrix[row][mid] == target:
                return True
            elif matrix[row][mid] < target:
                low = mid + 1
            else:
                high = mid - 1
        
        return False