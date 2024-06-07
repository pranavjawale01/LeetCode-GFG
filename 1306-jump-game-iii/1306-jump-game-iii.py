class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        if start < 0 or start >= len(arr):
            return False
        if arr[start] < 0:
            return False
        if arr[start] == 0:
            return True
        jump = arr[start]
        arr[start] = -arr[start]
        return self.canReach(arr, start + jump) or self.canReach(arr, start - jump)