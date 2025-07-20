class Solution {
    public String countOfAtoms(String formula) {
        Stack<Map<String, Integer>> stack = new Stack<>();
        int n = formula.length();
        int i = 0;
        stack.push(new HashMap<>());
        
        while (i < n) {
            if (formula.charAt(i) == '(') {
                stack.push(new HashMap<>());
                i++;
            } else if (formula.charAt(i) == ')') {
                Map<String, Integer> curr = stack.pop();
                i++;
                int mul = 0;
                while (i < n && Character.isDigit(formula.charAt(i))) {
                    mul = mul * 10 + (formula.charAt(i) - '0');
                    i++;
                }
                if (mul == 0) mul = 1;
                
                for (Map.Entry<String, Integer> entry : curr.entrySet()) {
                    curr.put(entry.getKey(), entry.getValue() * mul);
                }
                
                for (Map.Entry<String, Integer> entry : curr.entrySet()) {
                    stack.peek().put(entry.getKey(), stack.peek().getOrDefault(entry.getKey(), 0) + entry.getValue());
                }
            } else {
                StringBuilder currElement = new StringBuilder();
                currElement.append(formula.charAt(i++));
                while (i < n && Character.isLowerCase(formula.charAt(i))) {
                    currElement.append(formula.charAt(i++));
                }
                int count = 0;
                while (i < n && Character.isDigit(formula.charAt(i))) {
                    count = count * 10 + (formula.charAt(i) - '0');
                    i++;
                }
                if (count == 0) count = 1;
                stack.peek().put(currElement.toString(), stack.peek().getOrDefault(currElement.toString(), 0) + count);
            }
        }
        
        StringBuilder ans = new StringBuilder();
        TreeMap<String, Integer> mp = new TreeMap<>(stack.peek());
        for (Map.Entry<String, Integer> entry : mp.entrySet()) {
            ans.append(entry.getKey());
            if (entry.getValue() > 1) {
                ans.append(entry.getValue());
            }
        }
        
        return ans.toString();
    }
}