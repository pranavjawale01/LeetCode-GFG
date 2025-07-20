class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        int maxVal = Arrays.stream(nums).max().getAsInt();
        int n = maxVal + k + 2;
        int[] freq = new int[n];
        for (int x : nums) {
            freq[x]++;
        }
        int[] freqPref = new int[n];
        freqPref[0] = freq[0];
        for (int i = 1; i < n; i++) {
            freqPref[i] = freqPref[i - 1] + freq[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (freq[i] == 0 && numOperations == 0) continue;
            int l = Math.max(0, i - k);
            int r = Math.min(n - 1, i + k);
            int total = freqPref[r] - (l > 0 ? freqPref[l - 1] : 0);
            int temp = total - freq[i];
            int res = freq[i] + Math.min(numOperations, temp);
            ans = Math.max(ans, res);
        }
        return ans;
    }
}