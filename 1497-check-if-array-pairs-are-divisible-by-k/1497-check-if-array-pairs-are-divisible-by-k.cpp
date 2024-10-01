class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> brr(k, 0);
        for (int x : arr) {
            int rem = ((x % k) + k) % k;
            brr[rem]++;
        }
        if (brr[0] % 2 != 0) {
            return false;
        }
        for (int rem = 1; rem <= k / 2; rem++) {
            int half = k - rem;
            if (brr[half] != brr[rem]) {
                return false;
            }
        }
        return true;
    }
};