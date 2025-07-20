public class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stk = new Stack<>();
        int n = tokens.length;

        Map<String, BiFunction<Integer, Integer, Integer>> mp = new HashMap<>();
        mp.put("+", (a, b) -> a + b);
        mp.put("-", (a, b) -> a - b);
        mp.put("*", (a, b) -> a * b);
        mp.put("/", (a, b) -> a / b);

        for (int i = 0; i < n; i++) {
            if (mp.containsKey(tokens[i])) {
                int operator2 = stk.pop();
                int operator1 = stk.pop();
                int result = mp.get(tokens[i]).apply(operator1, operator2);
                stk.push(result);
            } else {
                stk.push(Integer.parseInt(tokens[i]));
            }
        }

        return stk.pop();
    }
}

/*
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
*/