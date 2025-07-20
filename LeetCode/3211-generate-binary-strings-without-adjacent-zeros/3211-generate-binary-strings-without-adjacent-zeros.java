class Solution {
    private List<String> ans = new ArrayList<>();
    public void solve(int n, String s, int i) {
        if (i == n) {
            ans.add(s);
            return;
        }
        if (i == 0 || s.charAt(i-1) == '1') {
            solve(n, s + '1', i+1);
            solve(n, s + '0', i+1);
        } else {
            solve(n, s + '1', i+1);
        }
    }
    public List<String> validStrings(int n) {
        solve(n, "", 0);
        return ans;
    }
}