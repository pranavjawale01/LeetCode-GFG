public class Solution {
    public boolean isValid(String s) {
        int slen = s.length();
        if (slen % 2 != 0) 
        {
            return false;
        }

        Stack<Character> st = new Stack<>();
        for (int i = 0; i < slen; i++) 
        {
            char currentChar = s.charAt(i);
            if (currentChar == '(' || currentChar == '{' || currentChar == '[') 
            {
                st.push(currentChar);
            } 
            else 
            {
                if (st.isEmpty()) 
                {
                    return false;
                }
                char top = st.peek();
                if((currentChar == ')' && top != '(') || ( currentChar == '}' && top != '{' )  || (currentChar == ']' && top != '[')) 
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.isEmpty();
    }
}