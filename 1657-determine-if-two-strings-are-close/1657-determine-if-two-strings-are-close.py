class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        m , n = len(word1) , len(word2)
        if m != n:
            return False
        v1 = [0] * 26
        v2 = [0] * 26
        
        for i in range(m):
            w1 , w2 = word1[i], word2[i]
            i1, i2 = ord(w1) - ord('a'), ord(w2) - ord('a')
            v1[i1] += 1
            v2[i2] += 1
        
        for i in range(26):
            if (v1[i] != 0 and v2[i] != 0) or (v1[i] == 0 and v2[i] == 0):
                continue
            else:
                return False
        
        v1.sort()
        v2.sort()
        
        return v1 == v2