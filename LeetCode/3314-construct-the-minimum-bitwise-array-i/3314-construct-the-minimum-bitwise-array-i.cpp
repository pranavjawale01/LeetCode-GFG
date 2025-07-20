class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, -1);
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int j = 0; j <= x; j++) {
                if ((j | (j + 1)) == x) {
                    arr[i] = j;
                    break;
                }
            }
        }
        return arr;
    }
};