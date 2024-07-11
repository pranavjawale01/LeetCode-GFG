class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> open;
        string result = "";
        for (char c : s) {
            if (c == '(') {
                int n = result.length();
                open.push(n);
            } else if (c == ')') {
                int start = open.top();
                open.pop();
                reverse(result.begin() + start, result.end());
            } else {
                result += c;
            }
        }
        return result;
    }
};