class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length() - 1;
        int count = 0;
        while (s[n] == ' ' && n >= 0) {
            n--;
        }
        while (s[n] != ' ' && n >= 0) {
            count++;
            n--;
        }
        return count;
    }
};

// class Solution {
// public:
//     int lengthOfLastWord(string s) {
//         int i = s.length() - 1, count = 0;

//         while (i >= 0 && s[i] == ' ') {
//             i--;
//         }

//         while (i >= 0 && s[i] != ' ') {
//             count++;
//             i--;
//         }

//         return count;
//     }
// };