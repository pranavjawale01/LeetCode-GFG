class Solution {
public:
    bool isMatch(string s, string p) {
        int sIndex = 0, pIndex = 0;
        int starIndex = -1, sTempIndex = -1;

        while (sIndex < s.size()) {
            if (pIndex < p.size() && (s[sIndex] == p[pIndex] || p[pIndex] == '?')) {
                sIndex++;
                pIndex++;
            } else if (pIndex < p.size() && p[pIndex] == '*') {
                starIndex = pIndex;
                sTempIndex = sIndex;
                pIndex++;
            } else if (starIndex != -1) {
                pIndex = starIndex + 1;
                sTempIndex++;
                sIndex = sTempIndex;
            } else {
                return false;
            }
        }

        while (pIndex < p.size() && p[pIndex] == '*') {
            pIndex++;
        }

        return pIndex == p.size();
    }
};