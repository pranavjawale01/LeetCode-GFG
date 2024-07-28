class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int threshold = sqrt(r);
        vector<int> prime(threshold+1, 1);
        prime[0] = 0, prime[1] = 0;
        for (int i = 2; i * i <= threshold; i++) {
            if (prime[i] == 1) {
                for (int j = i * i; j <= threshold; j += i) {
                    prime[j] = 0;
                }
            }
        }
        int count = 0;
        for (int i = 2; i <= threshold; i++) {
            if (prime[i] == 1) {
                int sq = i * i;
                if (sq >= l && sq <= r) {
                    count++;
                }
            }
        }
        return r - l + 1 - count;
    }
};