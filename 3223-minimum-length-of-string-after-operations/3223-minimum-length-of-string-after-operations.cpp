class Solution {
public:
    int minimumLength(string s) {
        int count[26];
        int remove = 0;
        for (char c : s) {
            count[c - 'a']++;
            if (count[c - 'a'] == 3) {
                count[c - 'a'] -= 2;
                remove += 2;
            }
        }
        return s.size() - remove;
    }
};




// class Solution {
// public:
//     int minimumLength(string s) {
//         sort(s.begin(), s.end());
//         int ans = 0;
//         int n = s.length();
//         for (int i = 0; i < n;) {
//             char c = s[i];
//             int count = 0;
//             while (c == s[i]) {
//                 i++;
//                 count++;
//             }
//             if (count <= 2) {
//                 ans += count;
//             } else {
//                 if (count % 2 == 1) {
//                     ans += 1;
//                 } else {
//                     ans += 2;
//                 }
//             }
//         }
//         return ans;
//     }
// };