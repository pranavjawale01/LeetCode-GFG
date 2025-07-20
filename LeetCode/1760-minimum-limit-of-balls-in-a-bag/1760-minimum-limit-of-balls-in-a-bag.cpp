class Solution {
public:
    bool solve(int maxBallsInBag, vector<int> &nums, int maxOperations) {
        int totalOperations = 0;
        for (int x : nums) {
            int operations = (int)ceil((double)x/maxBallsInBag) - 1;
            totalOperations += operations;
            if (totalOperations > maxOperations) {
                return false;
            }
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = 0;
        for (int x : nums) {
            r = max(r, x);
        }
        int ans = r;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (solve(mid, nums, maxOperations)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};