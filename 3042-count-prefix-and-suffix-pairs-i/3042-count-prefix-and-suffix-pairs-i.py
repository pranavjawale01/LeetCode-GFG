class Solution:
    def isPrefixAndSuffix(self, c, s):
        n = len(c)
        s1 = s[:n]
        s2 = s[-n:]
        return s1 == c and s2 == c

    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        count = 0
        n = len(words)
        for i in range(n - 1):
            for j in range(i + 1, n):
                if len(words[i]) <= len(words[j]) and self.isPrefixAndSuffix(words[i], words[j]):
                    count += 1
        return count