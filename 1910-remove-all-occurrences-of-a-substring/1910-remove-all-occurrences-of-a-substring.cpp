class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        int n = part.size();
        for (char &c : s) {
            ans.push_back(c);
            if (ans.size() >= n && ans.substr(ans.size() - n) == part) {
                ans.erase(ans.length() - n);
            }
        }
        return ans;
    }
};







// class Solution {
// public:
//     bool check(stack<char> &st, string &part, int n) {
//         stack<char> temp = st;
//         for (int i = n - 1; i >= 0; i--) {
//             if (temp.top() != part[i]) return false;
//             temp.pop();
//         }
//         return true;
//     }
//     string removeOccurrences(string s, string part) {
//         stack<char> st;
//         int m = s.size(), n = part.size();
//         for (int i = 0; i < m; i++) {
//             st.push(s[i]);
//             if (st.size() >= n && check(st, part, n)) {
//                 for (int j = 0; j < n; j++) st.pop();
//             }
//         }
//         string ans = "";
//         while (!st.empty()) ans.push_back(st.top()), st.pop();
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };








// // class Solution {
// // public:
// //     string removeOccurrences(string s, string part) {
// //         while (true) {
// //             int idx = s.find(part);
// //             if (idx == string::npos) {
// //                 break;
// //             }
// //             s.erase(idx, part.size());
// //         }
// //         return s;
// //     }
// // };