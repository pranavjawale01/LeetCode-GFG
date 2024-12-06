class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        banned_set = set(banned)
        count = 0
        total_sum = 0

        for i in range(1, n + 1):
            if i in banned_set:
                continue
            if total_sum + i > maxSum:
                break
            total_sum += i
            count += 1

        return count