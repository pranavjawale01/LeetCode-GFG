class Solution:
    def findWord(self, word: str, st: set()) -> str:
        for i in range(1, len(word)):
            if word[0:i] in st:
                return word[0:i]
        return word

    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        st = set(dictionary)
        result = []
        words = sentence.split()
        for word in words:
            result.append(self.findWord(word, st))
        return " ".join(result)