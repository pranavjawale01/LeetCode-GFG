class Solution:
    def maxOperations(self, s: str) -> int:
        t = [s[0]]
        count = 0
        one = 0
        
        for i in range(1, len(s)):
            if s[i] == '1':
                t.append('1')
            else:
                if s[i] != s[i - 1]:
                    t.append(s[i])
        
        for c in t:
            if c == '1':
                one += 1
            else:
                count += one
        
        return count