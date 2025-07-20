class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        if (m != n) {
            return false;
        }
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        
        for (int i = 0; i < m; i++) {
            char w1 = word1[i];
            char w2 = word2[i];
            v1[w1 - 'a']++;
            v2[w2 - 'a']++;
        }
            
        for (int i = 0; i < 26; i++) {
            if (v1[i] != 0 && v2[i] != 0) {
                continue;
            }
            if (v1[i] == 0 && v2[i] == 0) {
                continue;
            } else {
                return false;
            }
        }
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        return v1 == v2;
    }
};