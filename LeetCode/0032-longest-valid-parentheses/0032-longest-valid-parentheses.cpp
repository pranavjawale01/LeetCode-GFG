class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.length();
        int maxLen = 0;
        st.push(-1);
        for (int i = 0; i < n; i++) 
        {
            if (s[i] == '(') 
            {
                st.push(i);
            } 
            else 
            {
                st.pop();
                if (!st.empty()) 
                {
                    maxLen = max(maxLen, i - st.top());
                } 
                else 
                {
                    st.push(i);
                }
            }
        }
        return maxLen;
    }
};