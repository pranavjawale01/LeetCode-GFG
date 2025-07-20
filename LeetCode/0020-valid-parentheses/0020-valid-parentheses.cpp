class Solution {
public:
    bool isValid(string s) {
        int slen = s.length();
        if (slen % 2 != 0) 
        {
            return false;
        }
        
        stack<char> st;
        for (int i = 0; i < slen; i++) 
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') 
            {
                st.push(s[i]);
            } 
            else 
            {
                if (st.empty()) 
                {
                    return false;
                } 
                else if (st.top() =='(' && s[i] != ')' || st.top() =='{' && s[i] != '}' || (st.top() =='[' && s[i] != ']')) 
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};