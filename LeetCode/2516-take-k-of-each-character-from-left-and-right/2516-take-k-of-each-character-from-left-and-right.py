class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        n = len(s)
        a = b = c = 0

        for ch in s:
            if ch == 'a': a += 1
            if ch == 'b': b += 1
            if ch == 'c': c += 1

        if a < k or b < k or c < k:
            return -1

        i, j = 0, 0
        ans = 0

        while j < n:
            if s[j] == 'a': a -= 1
            if s[j] == 'b': b -= 1
            if s[j] == 'c': c -= 1

            while i <= j and (a < k or b < k or c < k):
                if s[i] == 'a': a += 1
                if s[i] == 'b': b += 1
                if s[i] == 'c': c += 1
                i += 1

            ans = max(ans, j - i + 1)
            j += 1

        return n - ans