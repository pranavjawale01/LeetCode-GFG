class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> output;
        int nl = to_string(low).length();
        int nh = to_string(high).length();

        for (int i = nl; i <= nh; i++) {
            for (int j = 0; j < 10 - i; j++) {
                int num = stoi(digits.substr(j, i));
                if (num >= low && num <= high) {
                    output.push_back(num);
                }
            }
        }
        return output;
    }
};

// class Solution {
// public:
//     bool sequential(int num) {
//         int digit = num % 10 + 1, temp;
//         while (num > 0) {
//             temp = num % 10;
//             if (digit - 1 == temp) {
//                 num = num / 10;
//                 digit = temp;
//             } else {
//                 return false;
//             }
//         }
//         return true;
//     }
//     int findIncrement(int num) {
//         int digits = 1;
//         while (num >= 10) {
//             num /= 10;
//             digits *= 10;
//         }
//         return digits;
//     }
//     vector<int> sequentialDigits(int low, int high) {
//         vector<int> output;
//         while (low <= high) {
//             if (sequential(low)) {
//                 output.push_back(low);
//                 int increment = findIncrement(low);
//                 low += increment;
//             } else {
//                 low++;
//             }
//         }
//         return output;
//     }
// };