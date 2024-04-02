class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mp1 = [-1] * 256
        mp2 = [-1] * 256
        n = len(s)
        for i in range(n):
            ch1 = s[i]
            ch2 = t[i]
            if (mp1[ord(ch1)] != -1 and mp1[ord(ch1)] != ord(ch2)) or (mp2[ord(ch2)] != -1 and mp2[ord(ch2)] != ord(ch1)):
                return False
            mp1[ord(ch1)] = ord(ch2)
            mp2[ord(ch2)] = ord(ch1)
        return True