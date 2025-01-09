class Trie:
    class Node:
        def __init__(self):
            self.links = [None] * 26
        
    def __init__(self):
        self.root = self.Node()
    
    def addWord(self, word: str) -> None:
        curr = self.root
        for c in word:
            idx = ord(c) - ord('a')
            if curr.links[idx] is None:
                curr.links[idx] = self.Node()
            curr = curr.links[idx]
    
    def find(self, x: str) -> bool:
        curr = self.root
        for c in x:
            idx = ord(c) - ord('a')
            if curr.links[idx] is None:
                return False
            curr = curr.links[idx]
        return True

class Solution:
    def countPrefixes(self, words: List[str], s: str) -> int:
        trie = Trie()
        trie.addWord(s)
        count = 0
        for x in words:
            if trie.find(x):
                count += 1
        return count
        



# class Solution:
#     def countPrefixes(self, words: List[str], s: str) -> int:
#         count = 0
#         for x in words:
#             if len(x) <= len(s) and s[0:len(x)] == x:
#                 count += 1
#         return count