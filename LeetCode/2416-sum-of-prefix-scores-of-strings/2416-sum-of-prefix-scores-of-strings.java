class Trie {
    int count;
    Trie[] child;
    public Trie() {
        count = 0;
        child = new Trie[26];
    }
}

class Solution {
    public Trie getTrieNode() {
        return new Trie();
    }

    public void insert(String word, Trie root) {
        Trie ptr = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (ptr.child[idx] == null) {
                ptr.child[idx] = getTrieNode();
            }
            ptr.child[idx].count += 1;
            ptr = ptr.child[idx];
        }
    }

    public int getScore(String word, Trie root) {
        Trie ptr = root;
        int score = 0;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            score += ptr.child[idx].count;
            ptr = ptr.child[idx];
        }
        return score;
    }

    public int[] sumPrefixScores(String[] words) {
        int n = words.length;
        Trie root = getTrieNode();
        for (String word : words) {
            insert(word, root);
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            ans[i] = getScore(words[i], root);
        }
        return ans;
    }
}