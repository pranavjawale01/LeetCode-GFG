struct TrieNode {
    TrieNode *children[10];
};

class Solution {
public:
    TrieNode *getTrieNode() {
        TrieNode* node = new TrieNode();
        for (int i = 0; i < 10; i++) {
            node->children[i] = nullptr;
        }
        return node;
    }

    void insert(int num, TrieNode *root) {
        TrieNode *crawl = root;
        string numstr = to_string(num);
        for (char c : numstr) {
            int idx = c - '0';
            if (!crawl->children[idx]) {
                crawl->children[idx] = getTrieNode();
            }
            crawl = crawl->children[idx];
        }
    }

    int search(int num, TrieNode *root) {
        TrieNode *crawl = root;
        string numstr = to_string(num);
        int len = 0;
        for (char c : numstr) {
            int idx = c - '0';
            if (crawl->children[idx]) {
                len++;
                crawl = crawl->children[idx];
            } else {
                break;
            }
        }
        return len;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode *root = getTrieNode();
        for (int num : arr1) {
            insert(num, root);
        }
        int ans = 0;
        for (int num : arr2) {
            ans = max(ans, search(num, root));
        }
        return ans;
    }
};








// class Solution {
// public:
//     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
//         unordered_set<int> st;
//         for (int val : arr1) {
//             while (!st.count(val) && val > 0) {
//                 st.insert(val);
//                 val /= 10;
//             }
//         }
//         int ans = 0;
//         for (int num : arr2) {
//             while (!st.count(num) && num > 0) {
//                 num /= 10;
//             }
//             if (num > 0) {
//                 ans = max(ans, (int)log10(num) + 1);
//             }
//         }
//         return ans;
//     }
// };