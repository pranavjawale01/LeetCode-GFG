class Solution {
    String ans = "";

    void solve(int n, int[] k, StringBuilder curr) {
        if (curr.length() == n) {
            k[0]--;
            if (k[0] == 0) {
                ans = curr.toString();
                return;
            }
            return;
        }
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (curr.length() > 0 && curr.charAt(curr.length() - 1) == ch) continue;
            curr.append(ch);
            solve(n, k, curr);
            if (!ans.isEmpty()) return;
            curr.deleteCharAt(curr.length() - 1);
        }
    }

    public String getHappyString(int n, int k) {
        solve(n, new int[]{k}, new StringBuilder());
        return ans;
    }
}






// class Solution {
//     List<String> ans = new ArrayList<>();

//     void solve(int n, StringBuilder curr) {
//         if (curr.length() == n) {
//             ans.add(curr.toString());
//             return;
//         }
//         for (char ch = 'a'; ch <= 'c'; ch++) {
//             if (curr.length() > 0 && curr.charAt(curr.length() - 1) == ch) continue;
//             curr.append(ch);
//             solve(n, curr);
//             curr.deleteCharAt(curr.length() - 1);
//         }
//     }

//     public String getHappyString(int n, int k) {
//         solve(n, new StringBuilder());
//         return ans.size() < k ? "" : ans.get(k - 1);
//     }
// }