class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        freq = [0] * 26
        for word in words2:
            temp = [0] * 26
            for c in word:
                temp[ord(c) - ord('a')] += 1
            for i in range(26):
                freq[i] = max(freq[i], temp[i])
        
        result = []
        for word in words1:
            temp = [0] * 26
            for c in word:
                temp[ord(c) - ord('a')] += 1
            if all(freq[i] <= temp[i] for i in range(26)):
                result.append(word)
        
        return result