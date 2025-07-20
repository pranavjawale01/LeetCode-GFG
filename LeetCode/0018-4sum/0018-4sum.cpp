class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 4) {
            return ans;
        }
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                int low = j + 1, high = n - 1;
                long long curr = (long long)target - (long long)nums[i] - (long long)nums[j];
                while (low < high) {
                    long long sum = (long long) (nums[low] + nums[high]);
                    if (sum > curr) {
                        high--;
                    } else if (sum < curr) {
                        low++;
                    } else {
                        vector<int> temp = {nums[i], nums[j], nums[low], nums[high]};
                        ans.push_back(temp);
                        while (low < high && nums[low] == temp[2]) {
                            low++;
                        }
                        while (low < high && nums[high] == temp[3]) {
                            high--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};