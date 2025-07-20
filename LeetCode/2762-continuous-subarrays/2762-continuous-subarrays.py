class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        minpq = []
        maxpq = []
        i = 0
        count = 0
        for j in range(n):
            heapq.heappush(minpq, (nums[j], j))
            heapq.heappush(maxpq, (-nums[j], j))
            while abs(-maxpq[0][0] - minpq[0][0]) > 2:
                i += 1
                while maxpq and maxpq[0][1] < i:
                    heapq.heappop(maxpq)
                while minpq and minpq[0][1] < i:
                    heapq.heappop(minpq)
            count += j - i + 1
        return count






# class Solution:
#     def continuousSubarrays(self, nums: List[int]) -> int:
#         n = len(nums)
#         count_map = Counter()
#         i = 0
#         count = 0
#         for j in range(n):
#             count_map[nums[j]] += 1
#             while max(count_map) - min(count_map) > 2:
#                 count_map[nums[i]] -= 1
#                 if count_map[nums[i]] == 0:
#                     del count_map[nums[i]]
#                 i += 1
#             count += j - i + 1
#         return count