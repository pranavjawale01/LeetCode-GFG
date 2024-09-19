class Solution {
    public List<Integer> solve(String s) {
        List<Integer> arr = new ArrayList<>();
        
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '+' || s.charAt(i) == '-' || s.charAt(i) == '*') {
                List<Integer> left  = solve(s.substring(0, i));
                List<Integer> right = solve(s.substring(i + 1));
                
                for (int x : left) {
                    for (int y : right) {
                        if (s.charAt(i) == '+') {
                            arr.add(x + y);
                        } else if (s.charAt(i) == '-') {
                            arr.add(x - y);
                        } else {
                            arr.add(x * y);
                        }
                    }
                }
            }
        }
        
        if (arr.isEmpty()) {
            arr.add(Integer.parseInt(s));
        }
        
        return arr;
    }

    public List<Integer> diffWaysToCompute(String expression) {
        return solve(expression);
    }
}