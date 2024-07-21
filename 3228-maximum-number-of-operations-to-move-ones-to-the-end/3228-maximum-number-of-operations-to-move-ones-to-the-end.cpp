class Solution {
public:
    int maxOperations(string s) {
        string t = "";
        int count = 0, one = 0;
        t += s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '1') {
                t += s[i];
            } else {
                if (s[i] != s[i-1]) {
                    t += s[i];
                }
            }
        }
        for (char c : t) {
            if (c == '1') {
                one++;
            } else {
                count += one;
            }
        }
        return count;
    }
};




// class Solution {
// public:
//     int maxOperations(string s) {
//         int n = s.length(), count = 0, ans = 0;
//         for (int i = 0; i < n; i++) {
//             if (s[i] == '0') {
//                 ans += count;
//                 while (i < n && s[i] != '1') {
//                     i++;
//                 }
//             }
//             count++;
//         }
//         return ans;
//     }
// };