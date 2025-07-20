class Solution {
    public int maxDepth(String s) {
        int count = 0, ans = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') {
                count++;
                ans = Math.max(ans, count);
            } else if (c == ')') {
                count--;
            }
        }
        return ans;
    }
}