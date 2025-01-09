class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        Trie trie;
        trie.addWord(s);
        int count = 0;
        for (string x : words) {
            if (trie.find(x)) {
                count++;
            }
        }
        return count;
    }

private:
    class Trie {
        struct Node {
            vector<Node*> links;
            Node() : links(26, nullptr){}
        };
        Node *root;

    public:
        Trie() {
            root = new Node();
        }

        void addWord(string &word) {
            Node *curr = root;
            for (char c : word) {
                if (curr->links[c-'a'] == nullptr) {
                    curr->links[c-'a'] = new Node();
                }
                curr = curr->links[c-'a'];
            }
        }

        bool find(string x) {
            Node *curr = root;
            for (char c : x) {
                if (curr->links[c-'a'] == nullptr) {
                    return false;
                }
                curr = curr->links[c-'a'];
            }
            return true;
        }
    };
};





// class Solution {
// public:
//     int countPrefixes(vector<string>& words, string s) {
//         int count = 0;
//         for (string &x : words) {
//             if (s.substr(0, x.size()) == x) count++;
//         }
//         return count;
//     }
// };