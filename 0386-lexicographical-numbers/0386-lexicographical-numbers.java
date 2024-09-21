class Solution {
    public void solve(int curr, int n, List<Integer> ans) {
        if (curr > n) {
            return;
        }
        ans.add(curr);
        for (int digit = 0; digit < 10; digit++) {
            int next = curr * 10 + digit;
            if (next > n) {
                return;
            }
            solve(next, n, ans);
        }
    }
    public List<Integer> lexicalOrder(int n) {
        List<Integer> ans = new ArrayList<>();
        for (int num = 1; num < 10; num++) {
            solve(num, n, ans);
        }
        return ans;
    }
}








// class Solution {
//     public List<Integer> lexicalOrder(int n) {
//         List<Integer> ans = new ArrayList<>();
//         for (int i = 1; i <= n; i++) {
//             ans.add(i);
//         }
//         Collections.sort(ans, (a, b) -> String.valueOf(a).compareTo(String.valueOf(b)));
//         return ans;
//     }
// }