class Solution {
public:
    vector<int> computeLPS(string &pattern) {
        int m = pattern.size();
        vector<int> lps(m, 0);
        int len = 0, i = 1;
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len-1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    bool kmpsearch(string &text, string &pattern) {
        int n = text.size(), m = pattern.size();
        vector<int> lps = computeLPS(pattern);
        int i = 0, j = 0;
        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }
            if (j == m) {
                return true;
            } else if (i < n && text[i] != pattern[j]) {
                if (j != 0) {
                    j = lps[j-1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i != j && kmpsearch(words[j], words[i])) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};





// class Solution {
// public:
//     vector<string> stringMatching(vector<string>& words) {
//         vector<string> ans;
//         for (string x : words) {
//             for (string y : words) {
//                 if (x == y) continue;
//                 if (y.find(x) != string::npos) {
//                     ans.push_back(x);
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };