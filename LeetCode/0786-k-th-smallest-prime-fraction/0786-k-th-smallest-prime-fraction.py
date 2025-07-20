class Solution:
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        pq = []
        n = len(arr)
        
        for i in range(n):
            heapq.heappush(pq, [1.0 * arr[i] / arr[-1], float(i), float(n - 1)])
        
        smallest = 1
        
        while smallest < k:
            vec = heapq.heappop(pq)
            i = int(vec[1])
            j = int(vec[2]) - 1
            
            heapq.heappush(pq, [1.0 * arr[i] / arr[j], float(i), float(j)])
            smallest += 1
        
        vec = heapq.heappop(pq)
        i = int(vec[1])
        j = int(vec[2])
        
        return [arr[i], arr[j]]


# class Solution:
#     def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
#         pq = []
#         n = len(arr)
#         for i in range(n):
#             for j in range(i + 1, n):
#                 div = arr[i] / arr[j]
#                 heapq.heappush(pq, (-div, arr[i], arr[j]))
#                 if len(pq) > k:
#                     heapq.heappop(pq)

#         vec = heapq.heappop(pq)
#         return [vec[1], vec[2]]


# class Solution:
#     def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
#         pq = []
#         n = len(arr)
#         for i in range(n):
#             for j in range(n):
#                 if i != j:
#                     heapq.heappush(pq, (-arr[i] / arr[j], arr[i], arr[j]))
#         while k > 1:
#             heapq.heappop(pq)
#             k -= 1
#         fraction = heapq.heappop(pq)
#         return [fraction[2], fraction[1]]