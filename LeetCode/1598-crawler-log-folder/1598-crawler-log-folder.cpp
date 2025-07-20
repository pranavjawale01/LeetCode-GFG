class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for (auto x : logs) {
            if (x == "../") {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (x != "./") {
                st.push(x);
            }
        }
        return st.size();
    }
};





// class Solution {
// public:
//     int minOperations(vector<string>& logs) {
//         int depth = 0;
//         for (auto x : logs) {
//             if (x == "../") {
//                 depth = max(0, depth - 1);
//             } else if (x == "./") {
//                 continue;
//             } else {
//                 depth++;
//             }
//         }
//         return depth;
//     }
// };