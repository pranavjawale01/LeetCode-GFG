class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        from functools import lru_cache

        count = [0] * 26
        for c in tiles:
            count[ord(c) - ord('A')] += 1

        self.ans = 0

        def solve():
            self.ans += 1
            for i in range(26):
                if count[i] == 0:
                    continue
                count[i] -= 1
                solve()
                count[i] += 1

        solve()
        return self.ans - 1