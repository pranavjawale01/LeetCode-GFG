class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stk = new Stack<>();
        int n = tokens.length;
        int result = 0;

        for (int i = 0; i < n; i++) {
            if (tokens[i].equals("+") || tokens[i].equals("-") || tokens[i].equals("*") || tokens[i].equals("/")) {
                int operator2 = stk.pop();
                int operator1 = stk.pop();
                if (tokens[i].equals("+")) {
                    result = operator1 + operator2;
                } else if (tokens[i].equals("-")) {
                    result = operator1 - operator2;
                } else if (tokens[i].equals("*")) {
                    result = operator1 * operator2;
                } else if (tokens[i].equals("/")) {
                    result = operator1 / operator2;
                }
                stk.push(result);
            } else {
                stk.push(Integer.parseInt(tokens[i]));
            }
        }

        return stk.peek();
    }
}