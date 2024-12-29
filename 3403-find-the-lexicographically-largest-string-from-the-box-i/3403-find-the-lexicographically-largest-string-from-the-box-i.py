class Solution:
    def answerString(self, word: str, numFriends: int) -> str:
        ans = ""
        maxc = max(word)
        n = len(word)
        
        if numFriends == 1:
            return word
        
        for i in range(n):
            if word[i] == maxc:
                length = min(n - i, n - numFriends + 1)
                if length <= 0:
                    continue
                temp = word[i:i + length]
                if temp > ans:
                    ans = temp
        
        return ans