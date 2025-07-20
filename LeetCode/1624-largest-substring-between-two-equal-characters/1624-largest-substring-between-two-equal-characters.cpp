class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> firstOccurrence;
        int maxLength = -1;

        for (int i = 0; i < s.length(); ++i) {
            if (firstOccurrence.find(s[i]) == firstOccurrence.end()) {
                firstOccurrence[s[i]] = i;
            } else {
                maxLength = max(maxLength, i - firstOccurrence[s[i]] - 1);
            }
        }

        return maxLength;
    }
};

// class Solution {
// public:
//     int maxLengthBetweenEqualCharacters(string s) {
//         int n = s.length();
//         int maxLen = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n && j != i; j++) {
//                 if (s[i] == s[j]) {
//                     maxLen = max(maxLen, abs(i - j));
//                 }
//             }
//         }
//         return maxLen;
//     }
// };