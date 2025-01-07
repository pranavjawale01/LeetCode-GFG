class Solution:
    def computeLPS(self, pattern):
        m = len(pattern)
        lps = [0] * m
        length = 0
        i = 1
        
        while i < m:
            if pattern[i] == pattern[length]:
                length += 1
                lps[i] = length
                i += 1
            else:
                if length != 0:
                    length = lps[length - 1]
                else:
                    lps[i] = 0
                    i += 1
        return lps
    
    def kmpSearch(self, text, pattern):
        n, m = len(text), len(pattern)
        lps = self.computeLPS(pattern)
        i = j = 0
        
        while i < n:
            if text[i] == pattern[j]:
                i += 1
                j += 1
            if j == m:
                return True
            elif i < n and text[i] != pattern[j]:
                if j != 0:
                    j = lps[j - 1]
                else:
                    i += 1
        return False
    
    def stringMatching(self, words):
        ans = []
        for i in range(len(words)):
            for j in range(len(words)):
                if i != j and self.kmpSearch(words[j], words[i]):
                    ans.append(words[i])
                    break
        return ans

        






# class Solution:
#     def stringMatching(self, words: List[str]) -> List[str]:
#         ans = []
#         for x in words:
#             for y in words:
#                 if x == y:
#                     continue
#                 if x in y:
#                     ans.append(x)
#                     break
#         return ans