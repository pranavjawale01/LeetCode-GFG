class Solution:
    def totalMoney(self, n: int) -> int:
        total , week = 0 , 1
        for i in range(1, n + 1):
            total += week
            week += 1
            if i % 7 == 0:
                week = i // 7 + 1
        return total