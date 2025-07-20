class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) 
        {
            char c = s.charAt(i);
            if (c == '(') 
            {
                stack.push(i);
            } 
            else 
            {
                stack.pop();
                if (!stack.isEmpty()) 
                {
                    maxLen = Math.max(maxLen, i - stack.peek());
                }
                else {
                    stack.push(i);
                }
            }
        }
        return maxLen;
    }
}