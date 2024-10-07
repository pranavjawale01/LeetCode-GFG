class Solution {
public:
    int minLength(string s) {
        int n = s.length();
        int i = 0, j = 1;
        while (j < n) {
            if (i < 0) {
                i++;
                s[i] = s[j];
            } else if ((s[i] == 'A' && s[j] == 'B') || (s[i] == 'C' && s[j] == 'D')) {
                i--;
            } else {
                i++;
                s[i] = s[j];
            }
            j++;
        }
        return i + 1;
    }
};







// class Solution {
// public:
//     int minLength(string s) {
//         stack<char> st;
//         for (char &c : s) {
//             if (st.empty()) {
//                 st.push(c);
//             } else {
//                 if (c == 'B' && st.top() == 'A') {
//                     st.pop();
//                 } else if (c == 'D' && st.top() == 'C') {
//                     st.pop();
//                 } else {
//                     st.push(c);
//                 }
//             }
//         }
//         return st.size();
//     }
// };




// class Solution {
// public:
//     int minLength(string s) {
//         while (s.find("AB") != -1 || s.find("CD") != -1) {
//             if (s.find("AB") != -1) {
//                 s.erase(s.find("AB"), 2);
//             } else if (s.find("CD") != -1) {
//                 s.erase(s.find("CD"), 2);
//             }
//         }
//         return s.length();
//     }
// };