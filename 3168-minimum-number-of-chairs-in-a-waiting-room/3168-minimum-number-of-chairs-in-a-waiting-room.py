class Solution:
    def minimumChairs(self, s: str) -> int:
        chair = 0
        available = 0
        for c in s:
            if c == 'E':
                available -= 1
                chair = min(chair, available)
            else:
                available += 1
                chair = min(chair, available)
        return chair * (-1)