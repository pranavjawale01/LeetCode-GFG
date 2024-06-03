class Solution:
    def judgeCircle(self, moves: str) -> bool:
        v, h = 0, 0
        for c in moves:
            if c == 'U':
                v += 1
            elif c == 'D':
                v -= 1
            elif c == 'R':
                h += 1
            elif c == 'L':
                h -= 1
        return v == 0 and h == 0