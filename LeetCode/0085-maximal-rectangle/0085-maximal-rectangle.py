class Solution:
    def getNSR(self, height: List[int]) -> List[int]:
        stack = deque()
        n = len(height)
        NSR = [0] * n
        for i in range(n - 1, -1, -1):
            while stack and height[stack[-1]] >= height[i]:
                stack.pop()
            NSR[i] = stack[-1] if stack else n
            stack.append(i)
        return NSR

    def getNSL(self, height: List[int]) -> List[int]:
        stack = deque()
        n = len(height)
        NSL = [-1] * n
        for i in range(n):
            while stack and height[stack[-1]] >= height[i]:
                stack.pop()
            NSL[i] = stack[-1] if stack else -1
            stack.append(i)
        return NSL

    def findMaxArea(self, height: List[int]) -> int:
        NSR = self.getNSR(height)
        NSL = self.getNSL(height)
        n = len(height)
        width = [0] * n
        for i in range(n):
            width[i] = NSR[i] - NSL[i] - 1
        maxArea = 0
        for i in range(n):
            a = width[i] * height[i]
            maxArea = max(maxArea, a)
        return maxArea

    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        m, n = len(matrix[0]), len(matrix)
        height = [0] * m
        maxArea = self.findMaxArea(height)
        for row in range(n):
            for col in range(m):
                height[col] = 0 if matrix[row][col] == '0' else height[col] + 1
            maxArea = max(maxArea, self.findMaxArea(height))
        return maxArea