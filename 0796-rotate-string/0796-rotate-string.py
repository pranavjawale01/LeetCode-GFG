class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        m, n = len(s), len(goal)
        if m != n:
            return False
        for i in range(1, m+1):
            s = s[1:] + s[0]
            if s == goal:
                return True
        return False