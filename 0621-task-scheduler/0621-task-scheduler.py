class Solution:
    def leastInterval(self, tasks: List[str], k: int) -> int:
        counts = collections.Counter(tasks)
        
        heap = []
        for v in counts.values():
            heapq.heappush(heap, -v)
        
        q = collections.deque()
        
        time = 0
        
        while heap or q:
            time += 1
            if not heap:
                time = q[0][1]
            else:
                n = heapq.heappop(heap)
                if n + 1 < 0:
                    q.append((n + 1, time + k))
            
            if q and q[0][1] == time:
                n, _ = q.popleft()
                heapq.heappush(heap, n)
        return time