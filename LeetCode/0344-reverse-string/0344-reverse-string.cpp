class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            s[i] = (char) s[i] + s[n - i - 1];
            s[n - i - 1] = (char) s[i] - s[n - i - 1];
            s[i] = (char) s[i] - s[n - i - 1];
        }
    }
};


// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         int n = s.size();
//         for (int i = 0; i < n / 2; i++) {
//             s[i] = (char) s[i] ^ s[n - i - 1];
//             s[n-i-1] = (char) s[i] ^ s[n - i - 1];
//             s[i] = (char) s[i] ^ s[n - i - 1];
//         }
//     }
// };


// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         int n = s.size();
//         for (int i = 0; i < n / 2; i++) {
//             swap(s[i], s[n-i-1]);
//         }
//     }
// };