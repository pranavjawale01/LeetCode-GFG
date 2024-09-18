class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto cmp = [](int a, int b) {
            string s1 = to_string(a), s2 = to_string(b);
            return (s1 + s2) > (s2 + s1);
        };

        sort(nums.begin(), nums.end(), cmp);

        if (nums[0] == 0) {
            return "0";
        }

        string ans = "";
        for (int num : nums) {
            ans += to_string(num);
        }

        return ans;
    }
};