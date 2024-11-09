class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int n = maxVal + k + 2;
        vector<int> freq(n, 0);
        for (int x : nums) freq[x]++;
        vector<int> freqPref(n, 0);
        freqPref[0] = freq[0];
        for (int i = 1; i < n; i++) freqPref[i] = freqPref[i-1] + freq[i];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (freq[i] == 0 && numOperations == 0) continue;
            int l = max(0, i - k), r = min(n - 1, i + k);
            int total = freqPref[r] - (l > 0 ? freqPref[l-1] : 0);
            int temp = total - freq[i];
            int res = freq[i] + min(numOperations, temp);
            ans = max(ans, res);
        }
        return ans;
    }
};