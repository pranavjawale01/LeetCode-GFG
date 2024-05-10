class Solution:
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        pq = []
        n = len(arr)
        for i in range(n):
            for j in range(n):
                if i != j:
                    heapq.heappush(pq, (-arr[i] / arr[j], arr[i], arr[j]))
        while k > 1:
            heapq.heappop(pq)
            k -= 1
        fraction = heapq.heappop(pq)
        return [fraction[2], fraction[1]]