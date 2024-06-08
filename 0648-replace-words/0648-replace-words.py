class Solution:
    class TrieNode:
        def __init__(self):
            self.child = [None] * 26
            self.isEnd = False
        
    def __init__(self):
        self.root = self.TrieNode()

    def insert(self, word):
        ptr = self.root
        for ch in word:
            idx = ord(ch) - ord('a')
            if not ptr.child[idx]:
                ptr.child[idx] = self.TrieNode()
            ptr = ptr.child[idx]
        ptr.isEnd = True
    
    def search(self, word):
        ptr = self.root
        for i, ch in enumerate(word):
            idx = ord(ch) - ord('a')
            if not ptr.child[idx]:
                return word
            ptr = ptr.child[idx]
            if ptr.isEnd:
                return word[:i+1]
        return word

    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        for word in dictionary:
            self.insert(word)
        words = sentence.split()
        result = []
        for word in words:
            result.append(self.search(word))
        return ' '.join(result)

        



# class Solution:
#     def findWord(self, word: str, st: set()) -> str:
#         for i in range(1, len(word)):
#             if word[0:i] in st:
#                 return word[0:i]
#         return word

#     def replaceWords(self, dictionary: List[str], sentence: str) -> str:
#         st = set(dictionary)
#         result = []
#         words = sentence.split()
#         for word in words:
#             result.append(self.findWord(word, st))
#         return " ".join(result)