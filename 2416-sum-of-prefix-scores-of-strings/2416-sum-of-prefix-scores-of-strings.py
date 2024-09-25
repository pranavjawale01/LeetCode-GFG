class Trie:
    def __init__(self):
        self.count = 0
        self.child = [None] * 26

class Solution:
    def getTrieNode(self):
        return Trie()

    def insert(self, word, root):
        ptr = root
        for c in word:
            idx = ord(c) - ord('a')
            if not ptr.child[idx]:
                ptr.child[idx] = self.getTrieNode()
            ptr.child[idx].count += 1
            ptr = ptr.child[idx]
    
    def getScore(self, word, root):
        ptr = root
        score = 0
        for c in word:
            idx = ord(c) - ord('a')
            score += ptr.child[idx].count
            ptr = ptr.child[idx]
        return score

    def sumPrefixScores(self, words: List[str]) -> List[int]:
        root = self.getTrieNode()
        for word in words:
            self.insert(word, root)
        return [self.getScore(word, root) for word in words]