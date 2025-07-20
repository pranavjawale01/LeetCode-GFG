class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26, 0), freq2(26, 0);
        int n = s1.length(), m = s2.length();
        for (int i = 0; i < n; i++) {
            freq1[s1[i] - 'a']++;
        }
        int i = 0, j = 0;
        while (i < m) {
            freq2[s2[i] - 'a']++;
            if (i >= n) {
                freq2[s2[j++] - 'a']--;
            }
            if (freq1 == freq2) {
                return true;
            }
            i++;
        }
        return false;
    }
};