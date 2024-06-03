class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        int sn = s.length(), tn = t.length();
        while (i < sn && j < tn) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return tn - j;
    }
};