class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        vector<int> freq(k+1);
        vector<int> vec;
        int n = nums.size();
        for (int i = 0; i < n / 2; i++) {
            int diff = abs(nums[i] - nums[n-i-1]);
            freq[diff]++;
            int a = nums[i];
            int b = nums[n-i-1];
            int threshold = max(max(a, b), k - min(a, b));
            vec.push_back(threshold);
        }
        sort(vec.begin(), vec.end());
        int ans = n / 2;
        n /= 2;
        for (int i = 0; i < k+1; i++) {
            int rest = n - freq[i];
            int greater = lower_bound(vec.begin(), vec.end(), i) - vec.begin();
            ans = min(ans, rest + greater);
        }
        return ans;
    }
};