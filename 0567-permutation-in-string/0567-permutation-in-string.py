class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        freq1 = Counter(s1)
        freq2 = Counter()
        n = len(s1)
        m = len(s2)
        
        i, j = 0, 0
        while i < m:
            freq2[s2[i]] += 1
            if i >= n:
                if freq2[s2[j]] == 1:
                    del freq2[s2[j]]
                else:
                    freq2[s2[j]] -= 1
                j += 1
            if freq1 == freq2:
                return True
            i += 1
        
        return False