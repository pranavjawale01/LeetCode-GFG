class Solution {
    public int Count(long curr, long next, int n) {
        int countNum = 0;
        while (curr <= n) {
            countNum += Math.min(next, n + 1) - curr;
            curr *= 10;
            next *= 10;
        }
        return countNum;
    }

    public int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {
            int count = Count(curr, curr + 1, n);
            if (count <= k) {
                curr++;
                k -= count;
            } else {
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
}








// MLE
// class Solution {
//     public void solve(int curr, int n, List<Integer> ans) {
//         if (curr > n) {
//             return;
//         }
//         ans.add(curr);
//         for (int digit = 0; digit < 10; digit++) {
//             int nextnum = curr * 10 + digit;
//             if (nextnum > n) {
//                 return;
//             }
//             solve(nextnum, n, ans);
//         }
//     }

//     public int findKthNumber(int n, int k) {
//         List<Integer> ans = new ArrayList<>();
//         for (int i = 1; i <= 9; i++) {
//             solve(i, n, ans);
//         }
//         return ans.get(k - 1);
//     }
// }