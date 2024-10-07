class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for (char &c : s) {
            if (st.empty()) {
                st.push(c);
            } else {
                if (c == 'B' && st.top() == 'A') {
                    st.pop();
                } else if (c == 'D' && st.top() == 'C') {
                    st.pop();
                } else {
                    st.push(c);
                }
            }
        }
        return st.size();
    }
};




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