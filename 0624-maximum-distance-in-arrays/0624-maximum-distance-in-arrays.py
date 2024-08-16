class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        ans = 0
        minEl = arrays[0][0]
        maxEl = arrays[0][-1]

        for i in range(1, len(arrays)):
            arr = arrays[i]
            distMin = abs(arr[0] - maxEl)
            distMax = abs(arr[-1] - minEl)
            
            ans = max(ans, distMin, distMax)

            minEl = min(minEl, arr[0])
            maxEl = max(maxEl, arr[-1])

        return ans