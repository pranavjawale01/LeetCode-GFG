class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        pq = []
        ans = 0
        
        for x in nums:
            heapq.heappush(pq, -x)
        
        while k:
            k -= 1
            top = -heapq.heappop(pq)
            ans += top
            heapq.heappush(pq, -ceil(top / 3))
        
        return ans