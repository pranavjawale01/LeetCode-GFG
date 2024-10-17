class Solution {
public:
    int maximumSwap(int num) {
        vector<int> maxRight(10, -1);
        string s = to_string(num);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int idx = s[i] - '0';
            maxRight[idx] = i;
        }
        for (int i = 0; i < n; i++) {
            char curr = s[i];
            int currDigit = curr - '0';
            for (int digit = 9; digit > currDigit; digit--) {
                if (maxRight[digit] > i) {
                    swap(s[i], s[maxRight[digit]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};






// class Solution {
// public:
//     int maximumSwap(int num) {
//         int len = log10(num) + 1;
//         string s = to_string(num);
//         vector<int> maxRight(len);
//         maxRight[len - 1] = len - 1;
//         for (int i = len - 2; i >= 0; i--) {
//             int rightMaxIdx = maxRight[i+1];
//             int rightMaxElement = s[rightMaxIdx];
//             maxRight[i] = (s[i] > rightMaxElement) ? i : rightMaxIdx;
//         }
//         for (int i = 0; i < len; i++) {
//             int maxRightIdx = maxRight[i];
//             int maxRightElement = s[maxRightIdx];
//             if (s[i] < maxRightElement) {
//                 swap(s[i], s[maxRightIdx]);
//                 return stoi(s);
//             }
//         }
//         return num;
//     }
// };