class Solution {
public:
    vector<int> ans;
    void dfs(int low, int high, int i, int num) {
        if (num >= low && num <= high) {
            ans.push_back(num);
        }
        if (num > high || i > 9) {
            return;
        }
        dfs(low, high, i+1, num*10 + i);
    }
    vector<int> sequentialDigits(int low, int high) {
        for (int i = 1; i <= 9; i++) {
            dfs(low, high, i, 0);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> sequentialDigits(int low, int high) {
//         vector<int> output = {12, 23, 34, 45, 56, 67, 78, 89,
//                             123, 234, 345, 456, 567, 678, 789,
//                             1234, 2345, 3456, 4567, 5678, 6789,
//                             12345, 23456, 34567, 45678, 56789,
//                             123456, 234567, 345678, 456789,
//                             1234567, 2345678, 3456789,
//                             12345678, 23456789,
//                             123456789};
//         vector<int> result;
//         int n = output.size();
//         for (int i = 0; i < n; i++) {
//             if (output[i] < low) {
//                 continue;
//             } 
//             if (output[i] > high) {
//                 break;
//             }
//             result.push_back(output[i]);
//         }
//         return result;
//     }
// };

// // class Solution {
// // public:
// //     vector<int> sequentialDigits(int low, int high) {
// //         queue<int> que;
// //         for (int i = 1; i <= 8; i++) {
// //             que.push(i);
// //         }
// //         vector<int> result;
// //         while (!que.empty()) {
// //             int temp = que.front();
// //             que.pop();
// //             if (temp >= low && temp <= high) {
// //                 result.push_back(temp);
// //             }
// //             int lastDigit = temp % 10;
// //             if (lastDigit + 1 <= 9) {
// //                 que.push(temp * 10 + (lastDigit + 1));
// //             }
// //         }
// //         return result;
// //     }
// // };

// // // class Solution {
// // // public:
// // //     vector<int> sequentialDigits(int low, int high) {
// // //         string digits = "123456789";
// // //         vector<int> output;
// // //         int nl = to_string(low).length();
// // //         int nh = to_string(high).length();

// // //         for (int i = nl; i <= nh; i++) {
// // //             for (int j = 0; j < 10 - i; j++) {
// // //                 int num = stoi(digits.substr(j, i));
// // //                 if (num >= low && num <= high) {
// // //                     output.push_back(num);
// // //                 }
// // //             }
// // //         }
// // //         return output;
// // //     }
// // // };

// // // // class Solution {
// // // // public:
// // // //     bool sequential(int num) {
// // // //         int digit = num % 10 + 1, temp;
// // // //         while (num > 0) {
// // // //             temp = num % 10;
// // // //             if (digit - 1 == temp) {
// // // //                 num = num / 10;
// // // //                 digit = temp;
// // // //             } else {
// // // //                 return false;
// // // //             }
// // // //         }
// // // //         return true;
// // // //     }
// // // //     int findIncrement(int num) {
// // // //         int digits = 1;
// // // //         while (num >= 10) {
// // // //             num /= 10;
// // // //             digits *= 10;
// // // //         }
// // // //         return digits;
// // // //     }
// // // //     vector<int> sequentialDigits(int low, int high) {
// // // //         vector<int> output;
// // // //         while (low <= high) {
// // // //             if (sequential(low)) {
// // // //                 output.push_back(low);
// // // //                 int increment = findIncrement(low);
// // // //                 low += increment;
// // // //             } else {
// // // //                 low++;
// // // //             }
// // // //         }
// // // //         return output;
// // // //     }
// // // // };