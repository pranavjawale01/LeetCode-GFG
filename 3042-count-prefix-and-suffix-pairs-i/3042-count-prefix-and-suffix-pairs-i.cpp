struct trieNode {
    trieNode *children[26];
    bool isEndOfWord;
};

trieNode *getNode() {
    trieNode *newNode = new trieNode();
    newNode->isEndOfWord = false;
    for (int i = 0; i < 26; i++) {
        newNode->children[i] = nullptr;
    }
    return newNode;
}

class Trie {

public:
    trieNode *root;
    Trie() {
        root = getNode();
    }

    void insert(string word) {
        trieNode *pCrawl = root;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (pCrawl->children[idx] == nullptr) {
                pCrawl->children[idx] = getNode();
            }
            pCrawl = pCrawl->children[idx];
        }
        pCrawl->isEndOfWord = true;
    }

    bool searchPrefix(string prefix) {
        trieNode *pCrawl = root;
        for (int i = 0; i < prefix.length(); i++) {
            int idx = prefix[i] - 'a';
            if (pCrawl->children[idx] == nullptr) {
                return false;
            }
            pCrawl = pCrawl->children[idx];
        }
        return true;
    }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for (int j = 0; j < n; j++) {
            Trie prefixTrie;
            Trie suffixTrie;
            
            prefixTrie.insert(words[j]);
            string reversed = words[j];
            reverse(reversed.begin(), reversed.end());
            suffixTrie.insert(reversed);
            for (int i = 0; i < j; i++) {
                if (words[i].length() > words[j].length()) continue;
                string rev = words[i];
                reverse(rev.begin(), rev.end());
                if (prefixTrie.searchPrefix(words[i]) && suffixTrie.searchPrefix(rev)) {
                    count++;
                }
            }
        }
        return count;
    }
};








// class Solution {
// public:
//     bool isPrefixAndSuffix(string &c, string &s) {
//         int n = c.length();
//         string s1 = s.substr(0, n);
//         string s2 = s.substr(s.length()-n, n);
//         return s1 == c && s2 == c;
//     }
//     int countPrefixSuffixPairs(vector<string>& words) {
//         int count = 0;
//         int n = words.size();
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (words[i].length() <= words[j].length() && isPrefixAndSuffix(words[i], words[j])) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };