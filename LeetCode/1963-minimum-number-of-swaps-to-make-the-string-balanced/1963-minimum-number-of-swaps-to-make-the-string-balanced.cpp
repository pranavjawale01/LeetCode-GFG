class Solution {
public:
    int minSwaps(string s) {
        int size = 0;
        for (char &c : s) {
            if (c == '[') {
                size++;
            } else if (size != 0) {
                size--;
            }
        }
        return (size + 1) / 2;
    }
};







// class Solution {
// public:
//     int minSwaps(string s) {
//         stack<char> st;
//         for (char &ch : s) {
//             if (ch == '[') {
//                 st.push(ch);
//             } else if (!st.empty()) {
//                 st.pop();
//             }
//         }
//         return (st.size() + 1) / 2;
//     }
// };