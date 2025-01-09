class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        trie = Trie()
        for word in words:
            trie.add_word(word)
        return trie.count_prefix(pref)

class Trie:
    class Node:
        def __init__(self):
            self.links = [None] * 26
            self.count = 0

    def __init__(self):
        self.root = self.Node()

    def add_word(self, word: str) -> None:
        curr = self.root
        for c in word:
            index = ord(c) - ord('a')
            if curr.links[index] is None:
                curr.links[index] = self.Node()
            curr = curr.links[index]
            curr.count += 1

    def count_prefix(self, pref: str) -> int:
        curr = self.root
        for c in pref:
            index = ord(c) - ord('a')
            if curr.links[index] is None:
                return 0
            curr = curr.links[index]
        return curr.count




# class Solution:
#     def prefixCount(self, words: List[str], pref: str) -> int:
#         n = len(pref)
#         count = 0
#         for x in words:
#             if len(x) >= n and x[0:n] == pref:
#                 count += 1
#         return count