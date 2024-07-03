class Solution:
    def minDifference(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 4:
            return 0
        
        pq_max = []
        pq_min = []
        
        for num in nums:
            heapq.heappush(pq_min, num)
            heapq.heappush(pq_max, -num)
            if len(pq_max) > 4:
                heapq.heappop(pq_max)
            if len(pq_min) > 4:
                heapq.heappop(pq_min)
        
        l, r = 3, n - 4
        
        while pq_max:
            nums[l] = -heapq.heappop(pq_max)
            nums[r] = heapq.heappop(pq_min)
            l -= 1
            r += 1
        
        return min(nums[n-1] - nums[3], nums[n-2] - nums[2], nums[n-3] - nums[1], nums[n-4] - nums[0])






# class Solution:
#     def minDifference(self, nums: List[int]) -> int:
#         n = len(nums)
#         if n <= 4:
#             return 0
        
#         nums.sort()
        
#         min_diff = float('inf')
#         min_diff = min(min_diff, nums[n-1] - nums[3])
#         min_diff = min(min_diff, nums[n-2] - nums[2])
#         min_diff = min(min_diff, nums[n-3] - nums[1])
#         min_diff = min(min_diff, nums[n-4] - nums[0])
        
#         return min_diff