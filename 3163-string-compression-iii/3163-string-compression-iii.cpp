class Solution {
public:
    string compressedString(string word) {
        unordered_map<char, int> mp;
        for (char c : word) {
            mp[c]++;
        }        
        string ans = "";
        for (char c : word) {
            if (mp[c]) {
                int count = min(mp[c], 9);
                ans += to_string(count) + c;
                mp[c] -= count;
            }
            if (mp[c] == 0) {
                mp.erase(c);
            }
        }
        return ans;
    }
};