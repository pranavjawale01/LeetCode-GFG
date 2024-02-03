class Solution {
public:
    int n;
    int mem[501];
    int solve(int i, vector<int>& arr, int k) {
        if (i >= n) {
            return 0;
        }
        if (mem[i] != -1) {
            return mem[i];
        }
        int result = 0;
        int curr_max = -1;

        for (int j = i; j < n && j - i + 1 <= k; j++) {
            curr_max = max(curr_max, arr[j]);
            result = max(result, (curr_max * (j - i + 1)) + solve(j+1, arr, k));
        }
        return mem[i] = result;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(mem, -1, sizeof(mem));
        return solve(0, arr, k);
    }
};