class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]--;
            mp[t[i]]++;
        }
        int count = 0;
        for (int i = 0; i < t.length(); i++) {
            if (mp[t[i]] > 0) {
                count += mp[t[i]];
                mp[t[i]] = 0;
            }
        }
        return count;
     }
};