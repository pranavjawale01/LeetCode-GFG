class Solution:
    def calGain(self, pass_, total):
        return (pass_ + 1) / (total + 1) - pass_ / total

    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        maxpq = []
        for pass_, total in classes:
            heapq.heappush(maxpq, (-self.calGain(pass_, total), pass_, total))

        while extraStudents > 0:
            gain, pass_, total = heapq.heappop(maxpq)
            pass_, total = pass_ + 1, total + 1
            heapq.heappush(maxpq, (-self.calGain(pass_, total), pass_, total))
            extraStudents -= 1

        ans = 0
        while maxpq:
            gain, pass_, total = heapq.heappop(maxpq)
            ans += pass_ / total

        return ans / len(classes)