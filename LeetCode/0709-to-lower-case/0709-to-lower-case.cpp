class Solution {
public:
    string toLowerCase(string s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            s[i] = tolower(s[i]);
        }
        return s;
    }
};


// class Solution {
// public:
//     string toLowerCase(string s) {
//         transform(s.begin(), s.end(), s.begin(), ::tolower);
//         return s;
//     }
// };