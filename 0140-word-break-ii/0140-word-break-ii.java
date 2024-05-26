class Solution {
    private List<String> result = new ArrayList<>();
    private Set<String> dict = new HashSet<>();

    public void solve(int i, String curr, String s) {
        if (i >= s.length()) {
            result.add(curr.trim());
            return;
        }
        for (int j = i; j < s.length(); j++) {
            String temp = s.substring(i, j + 1);
            if (dict.contains(temp)) {
                String original = curr;
                if (!curr.isEmpty()) {
                    curr += " ";
                }
                curr += temp;
                solve(j + 1, curr, s);
                curr = original;
            }
        }
    }

    public List<String> wordBreak(String s, List<String> wordDict) {
        dict.addAll(wordDict);
        solve(0, "", s);
        return result;
    }
}