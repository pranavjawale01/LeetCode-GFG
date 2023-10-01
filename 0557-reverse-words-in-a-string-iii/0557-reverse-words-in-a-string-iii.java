import java.util.Stack;

class Solution {
    public String reverseWords(String s) {
        int n = s.length();
        StringBuilder result = new StringBuilder();
        Stack<Character> stk = new Stack<>();
        for (int i = 0, j = 0; i < n; i++) 
        {
            if (s.charAt(i)==' ') 
            {
                while (!stk.isEmpty()) 
                {
                    result.append(stk.pop());
                    j++;
                }
                result.append(" ");
            } 
            else 
            {
                stk.push(s.charAt(i));
            }
        }
        while (!stk.isEmpty()) 
        {
            result.append(stk.pop());
        }
        return result.toString();
    }
}