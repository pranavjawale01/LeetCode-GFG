class Solution:
    def maximumLength(self, s: str) -> int:
        n = len(s)
        mp = {}
        maxlen = -1
        for i in range(n):
            length = 0
            curr = s[i]
            for j in range(i, n):
                if s[j] != curr:
                    break
                length += 1
                key = (curr, length)
                mp[key] = mp.get(key, 0) + 1
        for key, count in mp.items():
            if count >= 3:
                maxlen = max(maxlen, key[1])
        return -1 if maxlen == 0 else maxlen