class Solution {
    public boolean parseBoolExpr(String expression) {
        Stack<Character> stack = new Stack<>();
        for (char c : expression.toCharArray()) {
            if (c == 't' || c == 'f' || c == '!' || c == '&' || c == '|') {
                stack.push(c);
            } else if (c == ')') {
                boolean hasTrue = false, hasFalse = false;
                while (!stack.isEmpty() && stack.peek() != '!' && stack.peek() != '&' && stack.peek() != '|') {
                    char val = stack.pop();
                    if (val == 't') hasTrue = true;
                    if (val == 'f') hasFalse = true;
                }
                char op = stack.pop();
                if (op == '!') {
                    stack.push(hasTrue ? 'f' : 't');
                } else if (op == '&') {
                    stack.push(hasFalse ? 'f' : 't');
                } else {
                    stack.push(hasTrue ? 't' : 'f');
                }
            }
        }
        return stack.peek() == 't';
    }
}