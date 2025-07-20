class Solution:
    def stableMountains(self, height: List[int], threshold: int) -> List[int]:
        n = len(height)
        arr = []
        for i in range(n-1):
            if height[i] > threshold:
                arr.append(i+1)
        return arr