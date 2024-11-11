class Solution {
public:
    bool prime[1000];
    void seive() {
        fill(prime, prime+1000, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i < 1000; i++) {
            if (prime[i]) {
                for (int j = i * i; j < 1000; j += i) {
                    prime[j] = false;
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        seive();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                continue;
            }
            for (int p = 2; p < nums[i]; p++) {
                if (!prime[p]) continue;
                if (nums[i] - p < nums[i+1]) {
                    nums[i] -= p;
                    break;
                }
            }
            if (nums[i] >= nums[i+1]) {
                return false;
            }
        }
        return true;
    }
};