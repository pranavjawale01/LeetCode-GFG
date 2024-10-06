class Solution {
public:
    string intToBinary(int n) {
        string ans = "";
        while (n > 0) {
            ans = (n % 2 == 0 ? '0' : '1') + ans;
            n /= 2;
        }
        return ans == "" ? "0" : ans;
    }

    int maxGoodNumber(vector<int>& nums) {
        vector<string> ans;
        for (int x : nums) {
            ans.push_back(intToBinary(x));
        }
        auto cmp = [](string &a, string &b) {
            return a + b > b + a;
        };
        sort(ans.begin(), ans.end(), cmp);
        string res = "";
        for (auto &x : ans) {
            res += x;
        }
        long long finalAns = stoll(res, nullptr, 2);
        return finalAns;
    }
};