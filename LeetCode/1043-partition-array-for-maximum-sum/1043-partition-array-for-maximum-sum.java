class Solution {
    private int[] mem;
    private int n;
    public int solve(int i, int[] arr, int k) {
        if (i >= n) {
            return 0;
        }
        if (mem[i] != -1) {
            return mem[i];
        }
        int result = 0, currMax = -1;
        for (int j = i; j < n && j - i + 1 <= k; j++) {
            currMax = Math.max(currMax, arr[j]);
            result = Math.max(result, ((j - i + 1) * currMax) + solve(j + 1, arr, k));
        }
        return mem[i] = result;
    }
    public int maxSumAfterPartitioning(int[] arr, int k) {
        mem = new int[501];
        Arrays.fill(mem, -1);
        n = arr.length;
        return solve(0, arr, k);
    }
}