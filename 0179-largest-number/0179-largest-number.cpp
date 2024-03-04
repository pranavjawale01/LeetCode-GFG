class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto myComparator = [](int &a, int &b) {
            string c = to_string(a);
            string d = to_string(b);
            return c+d > d+c;
        };
        sort(nums.begin(), nums.end(), myComparator);
        if (nums[0] == 0) {
            return "0";
        } 
        string ans = "";
        for (int x : nums) {
            ans += to_string(x);
        }
        return ans;
    }
};
// class Solution {
// public:
//     static bool myComparator(int &s1, int &s2) {
//         string a = to_string(s1);
//         string b = to_string(s2);
//         return a+b > b+a;
//     }
//     string largestNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end(), myComparator);
//         if (nums[0] == 0) {
//             return "0";
//         } 
//         string ans = "";
//         for (int x : nums) {
//             ans += to_string(x);
//         }
//         return ans;
//     }
// };