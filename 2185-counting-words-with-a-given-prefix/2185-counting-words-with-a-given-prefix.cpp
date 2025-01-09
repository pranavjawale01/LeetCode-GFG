class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie;
        for (string &x : words) {
            trie.addWord(x);
        }
        return trie.countPrefix(pref);
    }

private:
    class Trie {
        struct Node {
            vector<Node*> links;
            int count;
            Node() : links(26, nullptr), count(0){}
        };
        Node *root;

    public:
        Trie() {
            root = new Node();
        }

        void addWord(string &word) {
            Node *curr = root;
            for (char c : word) {
                if (curr->links[c - 'a'] == nullptr) {
                    curr->links[c-'a'] = new Node();
                }
                curr = curr->links[c-'a'];
                curr->count++;
            }
        }

        int countPrefix(string &pref) {
            Node *curr = root;
            for (char c : pref) {
                if (curr->links[c-'a'] == nullptr) return 0;
                curr = curr->links[c-'a'];
            }
            return curr->count;
        }
    };
};






// class Solution {
// public:
//     int prefixCount(vector<string>& words, string pref) {
//         int n = pref.size();
//         int count = 0;
//         for (string x : words) {
//             if (x.substr(0, n) == pref) count++;
//         }
//         return count;
//     }
// };