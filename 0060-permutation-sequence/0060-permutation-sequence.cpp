class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        vector<int> nums;

        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
        }

        while (n > 0) {
            int fact = 1;
            for (int i = 1; i < n; ++i) {
                fact *= i;
            }

            int index = (k - 1) / fact;
            k = (k - 1) % fact + 1;

            result.push_back(nums[index] + '0');
            nums.erase(nums.begin() + index);

            --n;
        }

        return result;
    }
};