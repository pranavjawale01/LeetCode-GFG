class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> open;
        vector<int> door(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open.push(i);
            } else if (s[i] == ')') {
                int j = open.top();
                open.pop();
                door[i] = j;
                door[j] = i;
            }
        }
        string ans;
        int dir = 1;
        for (int i = 0; i < n; i += dir) {
            if (s[i] == '(' || s[i] == ')') {
                i = door[i];
                dir = -dir;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};




// class Solution {
// public:
//     string reverseParentheses(string s) {
//         stack<int> open;
//         string result = "";
//         for (char c : s) {
//             if (c == '(') {
//                 int n = result.length();
//                 open.push(n);
//             } else if (c == ')') {
//                 int start = open.top();
//                 open.pop();
//                 reverse(result.begin() + start, result.end());
//             } else {
//                 result += c;
//             }
//         }
//         return result;
//     }
// };