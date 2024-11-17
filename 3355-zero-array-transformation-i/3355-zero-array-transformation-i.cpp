class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> check(n+1, 0);
        for (auto x : queries) {
            int l = x[0];
            int r = x[1];
            check[l] -= 1;
            if (r + 1 < n) {
                check[r+1] += 1;
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
};