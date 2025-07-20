class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> st = new Stack<>();
        List<Integer> ans = new ArrayList<>();

        for (int x : asteroids) {
            if (x > 0) {
                st.push(x);
            } else {
                while (!st.isEmpty() && st.peek() > 0 && st.peek() < Math.abs(x)) {
                    st.pop();
                }
                if (st.isEmpty() || st.peek() < 0) {
                    ans.add(x);
                } else if (st.peek() == Math.abs(x)) {
                    st.pop();
                }
            }
        }

        int n = ans.size();
        while (!st.isEmpty()) {
            ans.add(st.pop());
        }

        Collections.reverse(ans.subList(n, ans.size()));

        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}