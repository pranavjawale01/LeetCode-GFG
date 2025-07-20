class Solution:
    def maxArea(self, height: List[int]) -> int:
        left, right, finalArea, currArea = 0, len(height)-1, 0, 0
        while left < right:
            currArea = min(height[left],height[right])*(right-left)
            finalArea = max(finalArea,currArea)
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return finalArea