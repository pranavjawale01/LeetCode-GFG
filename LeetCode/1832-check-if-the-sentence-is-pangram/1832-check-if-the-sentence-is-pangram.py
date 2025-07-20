class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        count = [0] * 26
        for c in sentence:
            count[ord(c) - ord('a')] += 1
        for i in range(26):
            if count[i] == 0:
                return False
        return True