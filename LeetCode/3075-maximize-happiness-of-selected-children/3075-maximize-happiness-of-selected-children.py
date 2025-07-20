class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort()
        happiness = happiness[::-1]
        sum = 0
        for i in range(k):
            if happiness[i] - i > 0:
                sum += happiness[i] - i
            else:
                return sum
        return sum