class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        n = len(word)
        index = -1
        for i in range(n):
            if word[i] == ch:
                index = i
                break
        if index == -1:
            return word
        word_list = list(word)
        for i in range((index + 1) // 2):
            word_list[i], word_list[index - i] = word_list[index - i], word_list[i]
        
        return ''.join(word_list)