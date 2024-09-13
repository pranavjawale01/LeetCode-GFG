class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = arr.length;
        for (int i = 1; i < n; i++) {
            arr[i] ^= arr[i-1];
        }
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; i++) {
            int l = queries[i][0], r = queries[i][1];
            ans[i] = arr[r] ^ (l == 0 ? 0 : arr[l-1]);
        }
        return ans;
    }
}