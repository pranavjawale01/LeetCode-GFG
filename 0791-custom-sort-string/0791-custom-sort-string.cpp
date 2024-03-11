class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }
        string ans = "";
        for (char ch : order) {
            if (mp[ch] > 0) {
                while (mp[ch] != 0) {
                    ans += ch;
                    mp[ch]--;
                }
            }
        }
        for (auto x : mp) {
            if (x.second > 0) {
                while (x.second != 0) {
                    ans += x.first;
                    x.second--;
                }
            }
        }
        return ans;
    }
};