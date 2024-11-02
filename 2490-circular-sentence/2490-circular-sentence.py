class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        n = len(sentence)
        
        if sentence[0] != sentence[-1]:
            return False
        
        words = sentence.split()
        
        for i in range(1, len(words)):
            if words[i][0] != words[i - 1][-1]:
                return False
        return True