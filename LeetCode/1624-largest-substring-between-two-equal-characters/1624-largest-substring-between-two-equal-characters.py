class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        n , max_len = len(s) , -1
        for i in range(n):
            for j in range(i+1, n):
                if s[i] == s[j]:
                    max_len = max(max_len, j - i - 1)
                    
        return max_len