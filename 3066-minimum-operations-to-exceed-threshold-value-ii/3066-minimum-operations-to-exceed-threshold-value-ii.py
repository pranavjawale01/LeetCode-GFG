class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        pq = []
        for x in nums:
            heapq.heappush(pq, x)
        count = 0
        while len(pq) > 1 and pq[0] < k:
            a = heapq.heappop(pq)
            b = heapq.heappop(pq)
            heapq.heappush(pq, min(a, b) * 2 + max(a, b))
            count += 1
        return count