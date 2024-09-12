class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;
        for (char c : allowed) {
            mask |= 1 << (c - 'a');
        }
        int count = 0;
        for (auto s : words) {
            bool flag = true;
            for (char c : s) {
                if (((mask >> (c - 'a')) & 1) == 0) {
                    flag = false;
                    break;
                }
            }
            count += flag;
        }
        return count;
    }
};









// class Solution {
// public:
//     int countConsistentStrings(string allowed, vector<string>& words) {
//         unordered_set<char> st(allowed.begin(), allowed.end());
//         int count = 0;
//         for (auto word : words) {
//             bool flag = false;
//             for (auto c : word) {
//                 if (st.find(c) == st.end()) {
//                     flag = true;
//                     break;
//                 }
//             }
//             if (flag) {
//                 continue;
//             }
//             count++;
//         }
//         return count;
//     }
// };