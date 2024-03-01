class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        string result = string(n, '0');
        int count_1 = count(s.begin(), s.end(), '1');
        int j = 0;
        while (count_1 > 1) {
            result[j] = '1';
            j++;
            count_1--;
        }
        result[n-1] = '1';
        return result;
    }
};

// class Solution {
// public:
//     string maximumOddBinaryNumber(string s) {
//         int n = s.length();
//         string result = string(n, '0');
//         int i = 0;
//         for (char &ch : s) {
//             if (ch == '1') {
//                 if (result[n-1] == '1') {
//                     result[i] = '1';
//                     i++;
//                 } else {
//                     result[n-1] = '1';
//                 }
//             }
//         }
//         return result;
//     }
// };

// class Solution {
// public:
//     string maximumOddBinaryNumber(string s) {
//         int count = 0;
//         int n = s.length();
//         for (int i = 0; i < n; i++) {
//             if (s[i] == '1') count++;
//         }
//         string ans = "";
//         for (int i = 0; i < count - 1 ; i++) {
//             ans += "1";
//         }
//         for (int i = 0; i < n - count; i++) {
//             ans += "0";
//         }
//         ans += "1";
//         return ans;
//     }
// };