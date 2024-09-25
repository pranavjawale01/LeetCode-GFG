struct Trie {
    int count = 0;
    Trie *child[26];
};

class Solution {
public:
    Trie *getTrieNode() {
        Trie *newNode = new Trie();
        for (int i = 0; i < 26; i++) {
            newNode->child[i] = nullptr;
        }
        newNode->count = 0;
        return newNode;
    }

    void insert(string &word, Trie *root) {
        Trie *crawl = root;
        for (char &c : word) {
            int idx = c - 'a';
            if (!crawl->child[idx]) {
                crawl->child[idx] = getTrieNode();
            }
            crawl->child[idx]->count += 1;
            crawl = crawl->child[idx];
        }
    }

    int getScore(string &word, Trie *root) {
        Trie *ptr = root;
        int score = 0;
        for (char &c : word) {
            int idx = c - 'a';
            score += ptr->child[idx]->count;
            ptr = ptr->child[idx];
        }
        return score;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        Trie *root = getTrieNode();
        for (string &word : words) {
            insert(word, root);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = getScore(words[i], root);
        }
        return ans;
    }
};