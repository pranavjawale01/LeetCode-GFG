class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        auto comparator = [&] (char a, char b) {
            if (mp[a] == mp[b]) {
                return a < b;
            }
            return mp[a] > mp[b];
        };
        sort(s.begin(), s.end(), comparator);
        return s;
    }
};