class Solution {
public:
    struct TrieNode {
        TrieNode *child[26];
        bool isEnd;
        TrieNode() : isEnd(false) {
            for (int i = 0; i < 26; ++i) {
                child[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    Solution() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* crawler = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!crawler->child[idx]) {
                crawler->child[idx] = new TrieNode();
            }
            crawler = crawler->child[idx];
        }
        crawler->isEnd = true;
    }

    string search(const string& word) {
        TrieNode* crawler = root;
        for (int i = 0; i < word.size(); ++i) {
            int idx = word[i] - 'a';
            if (!crawler->child[idx]) {
                return word;
            }
            crawler = crawler->child[idx];
            if (crawler->isEnd) {
                return word.substr(0, i + 1);
            }
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        for (const string& word : dictionary) {
            insert(word);
        }
        stringstream ss(sentence);
        string word;
        string result;
        while (ss >> word) {
            if (!result.empty()) {
                result += " ";
            }
            result += search(word);
        }
        return result;
    }
};



// class Solution {
// public:
//     string findWord(string &word, unordered_set<string> &st) {
//         for (int i = 1; i < word.length(); i++) {
//             string temp = word.substr(0, i);
//             if (st.find(temp) != st.end()) {
//                 return temp;
//             }
//         }
//         return word;
//     }
//     string replaceWords(vector<string>& dictionary, string sentence) {
//         unordered_set<string> st(dictionary.begin(), dictionary.end());
//         stringstream ss(sentence);
//         string word;
//         string result;
//         while (getline(ss, word, ' ')) {
//             result += findWord(word, st) + " ";
//         }
//         result.pop_back();
//         return result;
//     }
// };