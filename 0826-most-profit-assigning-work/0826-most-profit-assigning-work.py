class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        pq = []
        n = len(profit)
        m = len(worker)
        for i in range(n):
            heapq.heappush(pq, (-profit[i], difficulty[i]))
        worker.sort()
        totalProfit = 0
        i = m - 1
        while pq and i >= 0:
            if pq[0][1] > worker[i]:
                heapq.heappop(pq)
            else:
                totalProfit += -pq[0][0]
                i -= 1
        return totalProfit