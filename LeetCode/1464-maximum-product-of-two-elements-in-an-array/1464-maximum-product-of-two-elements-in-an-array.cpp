class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return ((nums[nums.size() - 1] - 1)* (nums[nums.size() - 2] - 1));
    }
};
/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        auto max1 = max_element(nums.begin(), nums.end());
        nums.erase(max1);
        auto max2 = max_element(nums.begin(), nums.end());
        return (*max1 - 1) * (*max2 - 1);
    }
};
*/