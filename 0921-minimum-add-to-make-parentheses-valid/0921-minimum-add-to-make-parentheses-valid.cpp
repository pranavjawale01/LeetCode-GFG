class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        for (char c : s) {
            if (c == '(') {
                open++;
            } else {
                if (open == 0) {
                    close++;
                } else {
                    open--;
                }
            }
        }
        return open + close;
    }
};








// class Solution {
// public:
//     int minAddToMakeValid(string s) {
//         stack<char> st;
//         int count = 0;
//         for (char c : s) {
//             if (c == '(') {
//                 st.push(c);
//             } else {
//                 if (st.empty()) {
//                     count++;
//                 } else {
//                     st.pop();
//                 }
//             }
//         }
//         return st.size() + count;
//     }
// };