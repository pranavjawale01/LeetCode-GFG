class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        n = len(arr)
        chunk = 0
        prefixSum = 0
        sortedPrefixSum = 0
        for i in range(n):
            prefixSum += arr[i]
            sortedPrefixSum += i
            if sortedPrefixSum == prefixSum:
                chunk += 1
        return chunk