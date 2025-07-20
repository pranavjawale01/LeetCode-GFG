class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.isEndOfWord = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for char in word:
            index = ord(char) - ord('a')
            if not node.children[index]:
                node.children[index] = TrieNode()
            node = node.children[index]
        node.isEndOfWord = True

    def searchPrefix(self, prefix):
        node = self.root
        for char in prefix:
            index = ord(char) - ord('a')
            if not node.children[index]:
                return False
            node = node.children[index]
        return True

class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        n = len(words)
        count = 0

        for j in range(n):
            prefixTrie = Trie()
            suffixTrie = Trie()

            prefixTrie.insert(words[j])

            reversed_word = words[j][::-1]
            suffixTrie.insert(reversed_word)

            for i in range(j):
                if len(words[i]) > len(words[j]):
                    continue

                rev = words[i][::-1]
                if prefixTrie.searchPrefix(words[i]) and suffixTrie.searchPrefix(rev):
                    count += 1

        return count
        






# class Solution:
#     def isPrefixAndSuffix(self, c, s):
#         n = len(c)
#         s1 = s[:n]
#         s2 = s[-n:]
#         return s1 == c and s2 == c

#     def countPrefixSuffixPairs(self, words: List[str]) -> int:
#         count = 0
#         n = len(words)
#         for i in range(n - 1):
#             for j in range(i + 1, n):
#                 if len(words[i]) <= len(words[j]) and self.isPrefixAndSuffix(words[i], words[j]):
#                     count += 1
#         return count