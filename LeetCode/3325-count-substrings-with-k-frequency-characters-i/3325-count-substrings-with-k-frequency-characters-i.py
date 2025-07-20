class Solution:
    def numberOfSubstrings(self, s: str, k: int) -> int:
        n = len(s)
        count = 0
        for i in range(n):
            mp = {}
            for j in range(i, n):
                if s[j] not in mp:
                    mp[s[j]] = 1
                else:
                    mp[s[j]] += 1
                if mp[s[j]] >= k:
                    count += n - j
                    break
        return count