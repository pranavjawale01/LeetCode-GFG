class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        count = [float('inf')] * 26
        n = len(words)
        
        for word in words:
            temp = [0] * 26
            for c in word:
                temp[ord(c) - ord('a')] += 1 
            for i in range(26):
                count[i] = min(count[i], temp[i])

        ans = []
        for i in range(26):
            while count[i] > 0:
                count[i] -= 1
                ans.append(chr(i + ord('a')))
        return ans