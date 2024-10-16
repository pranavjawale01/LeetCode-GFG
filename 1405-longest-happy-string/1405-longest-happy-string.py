class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        pq = []
        if a > 0:
            heapq.heappush(pq, (-a, 'a'))
        if b > 0:
            heapq.heappush(pq, (-b, 'b'))
        if c > 0:
            heapq.heappush(pq, (-c, 'c'))
        ans = []
        while pq:
            freq, ch = heapq.heappop(pq)
            freq = -freq
            if len(ans) >= 2 and ans[-1] == ch and ans[-2] == ch:
                if not pq:
                    break
                freq1, ch1 = heapq.heappop(pq)
                freq1 = -freq1
                ans.append(ch1)
                freq1 -= 1
                if freq1 > 0:
                    heapq.heappush(pq, (-freq1, ch1))
            else:
                ans.append(ch)
                freq -= 1
            if freq > 0:
                heapq.heappush(pq, (-freq, ch))
        return ''.join(ans)