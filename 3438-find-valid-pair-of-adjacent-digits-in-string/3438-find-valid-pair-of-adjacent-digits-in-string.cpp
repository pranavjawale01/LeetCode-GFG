class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        int n = s.size();
        for (int i = 0; i < n - 1; i++) {
            int a = s[i] - '0';
            int b = s[i+1] - '0';
            if (a != b && mp[s[i]] == a && mp[s[i+1]] == b) {
                return s.substr(i, 2);
            }
        }
        return "";
    }
};