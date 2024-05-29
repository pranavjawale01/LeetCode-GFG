class Solution {
public:
    int numSteps(string s) {
        int n = s.length();
        int op = 0;
        int carry = 0;
        for (int i = n - 1; i >= 1; i--) {
            if (((s[i] - '0') + carry) % 2 == 1) {
                op += 2;
                carry = 1;
            } else {
                op += 1;
            }
        }
        return op + carry;
    }
};



// class Solution {
// public:
//     int numSteps(string s) {
//         int count = 0;
//         while (s != "1") {
//             if (s.back() == '0') {
//                 s.pop_back();
//             } else {
//                 int i = s.length() - 1;
//                 while (i >= 0 && s[i] == '1') {
//                     s[i] = '0';
//                     i--;
//                 }
//                 if (i >= 0) {
//                     s[i] = '1';
//                 } else {
//                     s.insert(s.begin(), '1');
//                 }
//             }
//             count++;
//         }
//         return count;
//     }
// };


// // can't handle large string
// // class Solution {
// // public:
// //     int numSteps(string s) {
// //         long long num = 0;
// //         int n = s.length();
        
// //         for (int i = 0; i < n; i++) {
// //             if (s[i] == '1') {
// //                 num += pow(2, n - i - 1);
// //             }
// //         }

// //         int count = 0;
// //         while (num != 1) {
// //             if (num % 2 == 0) {
// //                 num /= 2;
// //             } else {
// //                 num += 1;
// //             }
// //             count++;
// //         }
        
// //         return count;
// //     }
// // };