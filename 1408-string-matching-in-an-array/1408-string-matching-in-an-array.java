class Solution {
    public List<String> stringMatching(String[] words) {
        List<String> ans = new ArrayList<>();
        for (String x : words) {
            for (String y : words) {
                if (x.equals(y)) continue;
                if (y.contains(x)) {
                    ans.add(x);
                    break;
                }
            }
        }
        return ans;
    }
}