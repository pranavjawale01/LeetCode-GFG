class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        n = len(times)
        order = list(range(n))
        
        order.sort(key=lambda x: times[x][0])
        
        hpq = list(range(n))
        heapq.heapify(hpq)
        
        lpq = []
        
        for i in order:
            arrival, leave = times[i]
            
            while lpq and lpq[0][0] <= arrival:
                heapq.heappush(hpq, heapq.heappop(lpq)[1])
            
            seat = heapq.heappop(hpq)
            
            if i == targetFriend:
                return seat
            
            heapq.heappush(lpq, (leave, seat))
        
        return -1