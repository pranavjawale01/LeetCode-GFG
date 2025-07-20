class Solution {
    public int numOfSubarrays(int[] arr) {
        int ans = 0;
        int mod = 1000000007;
        int oddCount = 0, evenCount = 1;
        int prefixSum = 0;

        for (int num : arr) {
            prefixSum += num;
            if (prefixSum % 2 == 0) {
                ans = (ans + oddCount) % mod;
                evenCount++;
            } else {
                ans = (ans + evenCount) % mod;
                oddCount++;
            }
        }

        return ans;
    }
}