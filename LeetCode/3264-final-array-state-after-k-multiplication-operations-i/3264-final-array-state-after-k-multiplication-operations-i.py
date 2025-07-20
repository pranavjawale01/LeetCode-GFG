class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        pq = [(nums[i], i) for i in range(len(nums))]
        heapq.heapify(pq)
        
        while k > 0:
            val, idx = heapq.heappop(pq)
            val *= multiplier
            heapq.heappush(pq, (val, idx))
            k -= 1
        
        while pq:
            val, idx = heapq.heappop(pq)
            nums[idx] = val
        
        return nums



# class Solution:
#     def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
#         for _ in range(k):
#             min_index = nums.index(min(nums))
#             nums[min_index] *= multiplier
#         return nums