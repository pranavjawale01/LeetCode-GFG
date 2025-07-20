class Solution {
    private int ans = 0;
    Set<String> st = new HashSet<>();
    void solve(String s, int i, String t) {
        if (i == s.length()) {
            ans = Math.max(ans, st.size());
            return;
        }
        for (int j = i; j < s.length(); j++) {
            t += s.charAt(j);
            if (!st.contains(t)) {
                st.add(t);
                solve(s, j+1, "");
                st.remove(t);
            }
        }
    }
    public int maxUniqueSplit(String s) {
        solve(s, 0, "");
        return ans;
    }
}