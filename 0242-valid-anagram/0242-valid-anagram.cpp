class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> sMap;
        unordered_map<char,int> tMap;
        for (char c : s) {
            sMap[c]++;
        }
        for (char c : t) {
            tMap[c]++;
        }        
        return sMap == tMap;
    }
};