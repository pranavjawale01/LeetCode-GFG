class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1, mp2;
        int n = s.length();        
        for(int i = 0; i < n; i++) {
            char ch1 = s[i];
            char ch2 = t[i];            
            if ((mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2) || (mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1)) {
                return false;
            }
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;            
        }        
        return true;
    }
};

// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         vector<int> mp1(256, -1);
//         vector<int> mp2(256, -1);
//         int n = s.length();        
//         for(int i = 0; i<n; i++) {
//             char ch1 = s[i];
//             char ch2 = t[i];            
//             if ((mp1[ch1] != -1 && mp1[ch1] != ch2) || (mp2[ch2] != -1 && mp2[ch2] != ch1)) {
//                 return false;
//             }
//             mp1[ch1] = ch2;
//             mp2[ch2] = ch1;            
//         }        
//         return true;
//     }
// };