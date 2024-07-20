class Solution:
    def minimumLength(self, s: str) -> int:
        count = [0] * 26
        remove = 0
        for c in s:
            i = ord(c) - ord('a')
            count[i] += 1
            if count[i] == 3:
                count[i] -= 2
                remove += 2
        return len(s) - remove