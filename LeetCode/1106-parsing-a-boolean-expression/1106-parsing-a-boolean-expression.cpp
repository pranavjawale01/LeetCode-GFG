class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for (char c : expression) {
            if (c == 't' || c == 'f' || c == '!' || c == '&' || c == '|') {
                st.push(c);
            } else if (c == ')') {
                bool hasTrue = false, hasFalse = false;
                while (st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    char val = st.top();
                    st.pop();
                    if (val == 't') hasTrue = true;
                    if (val == 'f') hasFalse = true;
                }
                char op = st.top();
                st.pop();
                if (op == '!') {
                    st.push(hasTrue ? 'f' : 't');
                } else if (op == '&') {
                    st.push(hasFalse ? 'f' : 't');
                } else {
                    st.push(hasTrue ? 't' : 'f');
                }
            }
        }
        return st.top() == 't';
    }
};