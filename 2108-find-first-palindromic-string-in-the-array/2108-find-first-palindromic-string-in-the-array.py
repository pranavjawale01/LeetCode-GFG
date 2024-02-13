class Solution:
    def isPalli(self, word: str) -> bool:
        newWord = word[::-1]
        return word == newWord

    def firstPalindrome(self, words: List[str]) -> str:
        for word in words:
            if self.isPalli(word):
                return word
        return ""