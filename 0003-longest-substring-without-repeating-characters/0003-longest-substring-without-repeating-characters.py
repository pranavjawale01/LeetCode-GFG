class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        left = 0
        maxLength = 0
        charIndex = {}

        for right in range (n):
            currentChar = s[right]
            if currentChar in charIndex:
                left = max(left,charIndex[currentChar]+1)
            
            charIndex[currentChar] = right
            currentLength = right - left + 1
            maxLength = max(maxLength,currentLength)

        return maxLength