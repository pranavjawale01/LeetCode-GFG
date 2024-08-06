class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        for (char c : word) {
            mp[c]++;
        }
        if (mp.size() <= 8) {
            return word.size();
        }
        if (mp.size() > 8 && mp.size() < 17) {
            return 8 + (mp.size() - 8) * 2;
        }
        if (mp.size() > 16 && mp.size() < 25) {
            return 8 + 16 + (mp.size() - 16) * 3;
        }
        return 8 + 16 + 24 + (mp.size() - 24) * 4;
    }
};