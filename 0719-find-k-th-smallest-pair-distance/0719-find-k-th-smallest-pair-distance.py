class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        maxEl = max(nums)
        arr = [0] * (maxEl + 1)
        n = len(nums)
        for i in range(n):
            for j in range(i+1, n):
                arr[abs(nums[i] - nums[j])] += 1

        for d in range(maxEl + 1):
            k -= arr[d]
            if k <= 0:
                return d
        
        return -1