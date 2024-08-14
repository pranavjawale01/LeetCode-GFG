class Solution:
    def slidingWindowCount(self, nums, d):
        i = 0
        j = 0
        n = len(nums)
        pair_count = 0
        
        while j < n:
            while j < n and nums[j] - nums[i] > d:
                i += 1
            pair_count += (j - i)
            j += 1
        
        return pair_count

    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        nums.sort()
        l = 0
        r = nums[-1] - nums[0]
        
        while l <= r:
            mid = l + (r - l) // 2
            count_pair = self.slidingWindowCount(nums, mid)
            
            if count_pair < k:
                l = mid + 1
            else:
                r = mid - 1
        
        return l




# class Solution:
#     def smallestDistancePair(self, nums: List[int], k: int) -> int:
#         maxEl = max(nums)
#         arr = [0] * (maxEl + 1)
#         n = len(nums)
#         for i in range(n):
#             for j in range(i+1, n):
#                 arr[abs(nums[i] - nums[j])] += 1

#         for d in range(maxEl + 1):
#             k -= arr[d]
#             if k <= 0:
#                 return d
        
#         return -1