class Solution {
    private String intToBinary(int n) {
        if (n == 0) return "0";
        StringBuilder ans = new StringBuilder();
        while (n > 0) {
            ans.append(n % 2 == 0 ? '0' : '1');
            n /= 2;
        }
        return ans.reverse().toString();
    }

    public int maxGoodNumber(int[] nums) {
        List<String> ans = new ArrayList<>();
        for (int x : nums) {
            ans.add(intToBinary(x));
        }
        Comparator<String> cmp = (a, b) -> (a + b).compareTo(b + a) > 0 ? -1 : 1;
        ans.sort(cmp);
        StringBuilder res = new StringBuilder();
        for (String x : ans) {
            res.append(x);
        }
        return (int) Long.parseLong(res.toString(), 2);
    }
}