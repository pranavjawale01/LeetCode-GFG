class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> vec1(26, 0);
        vector<int> vec2(26, 0);
        for (char c : s1) {
            vec1[c - 'a']++;
        }
        for (char c : s2) {
            vec2[c - 'a']++;
        }
        if (vec1 == vec2) {
            return true;
        }
        return false;
    }
};