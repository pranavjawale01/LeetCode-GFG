class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        row, col = len(points), len(points[0])
        ans = [0] * col
        ans = points[0]

        for i in range(1, row):
            left = [0] * col
            right = [0] * col

            left[0] = ans[0]
            for j in range(1, col):
                left[j] = max(left[j-1] - 1, ans[j])
            
            right[col-1] = ans[col-1]
            for j in range(col-2, -1, -1):
                right[j] = max(right[j+1] - 1, ans[j])
        
            for j in range(col):
                ans[j] = points[i][j] + max(left[j], right[j])
        
        return max(ans)