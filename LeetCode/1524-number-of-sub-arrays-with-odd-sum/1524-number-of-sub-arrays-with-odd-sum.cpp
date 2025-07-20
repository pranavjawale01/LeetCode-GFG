class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0;
        int mod = 1e9 + 7;
        long long odd_count = 0, even_count = 1;
        long long prefix_sum = 0;
        for (int num : arr) {
            prefix_sum += num;
            if (prefix_sum % 2 == 0) {
                ans = (ans + odd_count) % mod;
                even_count++;
            } else {
                ans = (ans + even_count) % mod;
                odd_count++;
            }
        }
        return ans;
    }
};