class Solution:
    def threeConsecutiveOdds(self, arr: list[int]) -> bool:
        n = len(arr)
        for i in range(n - 2):
            if (arr[i] & 1) == 1 and (arr[i + 1] & 1) == 1 and (arr[i + 2] & 1) == 1:
                return True
        return False