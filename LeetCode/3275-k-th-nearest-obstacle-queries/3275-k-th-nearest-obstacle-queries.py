class Solution:
    def resultsArray(self, queries: List[List[int]], k: int) -> List[int]:
        n = len(queries)
        ans = []
        pq = []
        
        for i in range(n):
            x, y = queries[i]
            dist = abs(x) + abs(y)
            heapq.heappush(pq, -dist)
            
            if len(pq) > k:
                heapq.heappop(pq)
            
            if len(pq) == k:
                ans.append(-pq[0])
            else:
                ans.append(-1)
        
        return ans