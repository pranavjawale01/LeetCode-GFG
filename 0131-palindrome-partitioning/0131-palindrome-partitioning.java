class Solution {
    public List<List<String>> ans = new ArrayList<>();

    public boolean isPalindrome(String s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s.charAt(i) != s.charAt(n - i - 1)) {
                return false;
            }
        }
        return true;
    }

    void solve(String s, List<String> temp, int i) {
        if (i == s.length()) {
            ans.add(new ArrayList<>(temp));
            return;
        }
        for (int j = i; j < s.length(); j++) {
            String sub = s.substring(i, j + 1);
            if (isPalindrome(sub)) {
                temp.add(sub);
                solve(s, temp, j + 1);
                temp.remove(temp.size() - 1);
            }
        }
    }

    public List<List<String>> partition(String s) {
        List<String> temp = new ArrayList<>();
        solve(s, temp, 0);
        return ans;
    }
}