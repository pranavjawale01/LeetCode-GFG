class Solution:
    def isPossibleToRearrange(self, s: str, t: str, k: int) -> bool:
        n = len(s)
        if k == 1:
            return s == t

        chunk = n // k
        s_chunk = [s[i * chunk:(i + 1) * chunk] for i in range(k)]
        t_chunk = [t[i * chunk:(i + 1) * chunk] for i in range(k)]

        s_chunk.sort()
        t_chunk.sort()

        return s_chunk == t_chunk