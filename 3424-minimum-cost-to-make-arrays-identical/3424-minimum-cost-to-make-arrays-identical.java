class Solution {
    public long minCost(int[] arr, int[] brr, long k) {
        if (Arrays.equals(arr, brr)) return 0;
        int n = arr.length;
        if (n == 1) return Math.abs(arr[0] - brr[0]);
        long ans2 = 0;
        for (int i = 0; i < n; i++) {
            ans2 += Math.abs(arr[i] - brr[i]);
        }
        Arrays.sort(arr);
        Arrays.sort(brr);
        long ans1 = k;
        for (int i = 0; i < n; i++) {
            ans1 += Math.abs(arr[i] - brr[i]);
        }
        return Math.min(ans1, ans2);
    }
}