class Solution {
public:
    bool solve(vector<int> nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> check(n+1, 0);
        for (int i = 0; i <= k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            check[l] -= val;
            if (r + 1 < n) {
                check[r+1] += val;
            }
        }
        int temp = 0;
        for (int i = 0; i < n; i++) {
            temp += check[i];
            nums[i] += temp;
            if (nums[i] < 0) nums[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        bool flag = true;
        for (int x : nums) {
            if (x != 0) {
                flag = false;
                break;
            }
        }
        if (flag) return 0;
        int ans = -1;
        int low = 0, high = queries.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (solve(nums, queries, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans == -1 ? -1 : ans + 1;
    }
};