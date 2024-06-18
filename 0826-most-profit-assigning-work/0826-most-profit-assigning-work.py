class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        jobs = sorted(zip(difficulty, profit))
        worker.sort()
        
        totalProfit = 0
        maxProfit = 0
        j = 0
        n = len(jobs)
        
        for level in worker:
            while j < n and level >= jobs[j][0]:
                maxProfit = max(maxProfit, jobs[j][1])
                j += 1
            totalProfit += maxProfit
        
        return totalProfit



# class Solution:
#     def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
#         n = len(profit)
#         m = len(worker)
#         vec = []
#         for i in range(n):
#             vec.append([difficulty[i], profit[i]])
#         vec.sort()
#         for i in range(1, len(vec)):
#             vec[i][1] = max(vec[i][1], vec[i-1][1])
#         totalProfit = 0
#         for i in range(m):
#             level = worker[i]
#             l = 0
#             r = len(vec) - 1
#             maxProfit = 0
#             while l <= r:
#                 mid = l + (r - l) // 2
#                 if vec[mid][0] <= level:
#                     maxProfit = max(maxProfit, vec[mid][1])
#                     l = mid + 1
#                 else:
#                     r = mid - 1
#             totalProfit += maxProfit
#         return totalProfit



# class Solution:
#     def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
#         pq = []
#         n = len(profit)
#         m = len(worker)
#         for i in range(n):
#             heapq.heappush(pq, (-profit[i], difficulty[i]))
#         worker.sort()
#         totalProfit = 0
#         i = m - 1
#         while pq and i >= 0:
#             if pq[0][1] > worker[i]:
#                 heapq.heappop(pq)
#             else:
#                 totalProfit += -pq[0][0]
#                 i -= 1
#         return totalProfit