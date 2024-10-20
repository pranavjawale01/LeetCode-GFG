class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                if (freq[s[j] - 'a'] >= k) {
                    count += n - j;
                    break;
                }
            }
        }
        return count;
    }
};







// class Solution {
// public:
//     int numberOfSubstrings(string s, int k) {
//         int n = s.length();
//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             vector<int> freq(26, 0);
//             for (int j = i; j < n; j++) {
//                 freq[s[j] - 'a']++;
//                 for (int i = 0; i < 26; i++) {
//                     if (freq[i] >= k) {
//                         count++;
//                         break;
//                     }
//                 }
//             }
//         }
//         return count;
//     }
// };