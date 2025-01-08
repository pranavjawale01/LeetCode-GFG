class Solution {
public:
    bool isPrefixAndSuffix(string &c, string &s) {
        int n = c.length();
        string s1 = s.substr(0, n);
        string s2 = s.substr(s.length()-n, n);
        return s1 == c && s2 == c;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (words[i].length() <= words[j].length() && isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }
};