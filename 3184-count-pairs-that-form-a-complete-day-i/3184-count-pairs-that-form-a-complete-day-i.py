class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:
        n = len(hours)
        count = 0
        for i in range(n-1):
            for j in range(i+1, n):
                if (hours[i] + hours[j]) % 24 == 0:
                    count += 1
        return count