class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        pq = [-x for x in gifts]
        heapq.heapify(pq)
        ans = sum(gifts)
        for _ in range(k):
            maxEl = -heapq.heappop(pq)
            sqrt = int(math.sqrt(maxEl))
            ans -= (maxEl - sqrt)
            heapq.heappush(pq, -sqrt)
        return ans