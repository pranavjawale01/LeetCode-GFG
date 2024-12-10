class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        map<pair<char, int>, int> mp;
        int maxlen = -1;
        for (int i = 0; i < n; i++) {
            int len = 0;
            char curr = s[i];
            for (int j = i; j < n && s[j] == curr; j++) {
                len++;
                mp[{curr, len}]++;
            }
        }
        for (auto &x : mp) {
            if (x.second >= 3) {
                maxlen = max(maxlen, x.first.second);
            }
        }
        return maxlen == 0 ? -1 : maxlen;
    }
};