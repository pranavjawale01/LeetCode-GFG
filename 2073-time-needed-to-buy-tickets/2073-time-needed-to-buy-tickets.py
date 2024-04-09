class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        n = len(tickets)
        q = deque()
        for i in range(n):
            q.append(i)
        time = 0
        while True:
            if tickets[k] == 0:
                break
            curr = q[0]
            tickets[curr] -= 1
            time += 1
            q.popleft()
            if tickets[curr] > 0:
                q.append(curr)
        return time