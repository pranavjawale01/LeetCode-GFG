import java.util.Stack;

class Solution {
    public boolean backspaceCompare(String s, String t) {
        Stack<Character> s_stack = new Stack<>();
        Stack<Character> t_stack = new Stack<>();
        char[] sChars = s.toCharArray();
        char[] tChars = t.toCharArray();
        for(char c : sChars) 
        {
            if(c != '#') 
            {
                s_stack.push(c);
            } 
            else if(!s_stack.isEmpty()) 
            {
                s_stack.pop();
            }
        }     
        for(char c : tChars) 
        {
            if(c != '#') 
            {
                t_stack.push(c);
            } 
            else if(!t_stack.isEmpty()) 
            {
                t_stack.pop();
            }
        }        
        return s_stack.equals(t_stack);
    }
}