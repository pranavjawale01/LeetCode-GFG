class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        i, j = 0, 0
        currCost, maxLen = 0, 0
        n = len(s)

        while j < n:
            currCost += abs(ord(s[j]) - ord(t[j]))
            while currCost > maxCost:
                currCost -= abs(ord(s[i]) - ord(t[i]))
                i += 1
            maxLen = max(maxLen, j - i + 1)
            j += 1
        
        return maxLen