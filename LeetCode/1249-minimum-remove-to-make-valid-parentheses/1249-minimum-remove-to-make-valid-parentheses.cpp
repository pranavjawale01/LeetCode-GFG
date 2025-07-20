class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        string temp = "";
        
        for(char c:s) {
            if(c == '(') {
                open++;
            } else if(c == ')') {
                if(open == 0)
                    continue;
                open--;
            }
            
            temp.push_back(c);
        }
        
        int n = temp.length();
        string result = "";
        for(int i = n-1; i>=0; i--) {
            if(temp[i] == '(' && open-- > 0)
                continue;
            result.push_back(temp[i]);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

// class Solution {
// public:
//     string minRemoveToMakeValid(string s) {
//         int open = 0;
//         int n = s.length();
//         string ans = "";
//         for (int i = 0; i < n; i++) {
//             if (s[i] >= 'a' && s[i] <= 'z') {
//                 ans.push_back(s[i]);
//             } else if (s[i] == '(') {
//                 open++;
//                 ans.push_back(s[i]);
//             } else if (open > 0) {
//                 open--;
//                 ans.push_back(s[i]);
//             }
//         }
//         string result = "";
//         int close = 0;
//         n = ans.length();
//         for (int i = n - 1; i >= 0; i--) {
//             if (ans[i] >= 'a' && ans[i] <= 'z') {
//                 result.push_back(ans[i]);
//             } else if (ans[i] == ')') {
//                 close++;
//                 result.push_back(ans[i]);
//             } else if (close > 0) {
//                 close--;
//                 result.push_back(ans[i]);
//             }
//         }
//         reverse(begin(result), end(result));
//         return result;
//     }
// };

// // class Solution {
// // public:
// //     string minRemoveToMakeValid(string s) {
// //         stack<int> st;
// //         int n = s.length();
// //         unordered_set<int> remove_idx;
// //         for (int i = 0; i < n; i++) {
// //             if (s[i] == '(') {
// //                 st.push(i);
// //             } else if (s[i] == ')') {
// //                 if (st.empty()) {
// //                     remove_idx.insert(i);
// //                 } else {
// //                     st.pop();
// //                 }
// //             }
// //         }
// //         while (!st.empty()) {
// //             remove_idx.insert(st.top());
// //             st.pop();
// //         }
// //         string ans = "";
// //         for (int i = 0; i < n; i++) {
// //             if (remove_idx.find(i) == remove_idx.end()) {
// //                 ans.push_back(s[i]);
// //             }
// //         }
// //         return ans;
// //     }
// // };