class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for(int j = i + 1; j < nums.size() - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int front = j + 1;
                int back = nums.size() - 1;
                long long newTarget = static_cast<long long>(target) - nums[i] - nums[j];
                while(front < back) {
                    long long sum = static_cast<long long>(nums[front]) + static_cast<long long>(nums[back]);
                    if(sum > newTarget) {
                        back--;
                    } 
                    else if(sum < newTarget) {
                        front++;
                    } 
                    else {
                        vector<int> quad = {nums[i], nums[j], nums[front], nums[back]};
                        result.push_back(quad);
                        while(front < back && nums[front] == quad[2]) {
                            front++;
                        }
                        while(front < back && nums[back] == quad[3]) {
                            back--;
                        }
                    }
                }
            }
        }
        return result;
    }
};