class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        n = len(arr)
        j = n - 1
        while j > 0 and arr[j] >= arr[j-1]:
            j -= 1
        if j == 0:
            return 0
        i = 0
        ans = j
        while i < j and (i == 0 or arr[i] >= arr[i-1]):
            while j < n and arr[i] > arr[j]:
                j += 1
            ans = min(ans, j - i - 1)
            i += 1
        return ans