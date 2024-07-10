class Solution {
    public int minOperations(String[] logs) {
        Stack<String> st = new Stack<>();
        for (String x : logs) {
            if (x.equals("../")) {
                if (!st.isEmpty()) {
                    st.pop();
                }
            } else if (!x.equals("./")) {
                st.push(x);
            }
        }
        return st.size();
    }
}



/*
class Solution {
    public int minOperations(String[] logs) {
        int depth = 0;
        for (String x : logs) {
            if (x.equals("../")) {
                depth = Math.max(0, depth - 1);
            } else if (x.equals("./")) {
                continue;
            } else {
                depth++;
            }
        }
        return depth;
    }
}
*/