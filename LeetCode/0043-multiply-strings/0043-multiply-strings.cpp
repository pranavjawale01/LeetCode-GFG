class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        vector<int> result(n+m,0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int product = (num1[i] - '0')*(num2[j] - '0');
                int sum = product + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        string ans;
        for (int digit : result) {
            if (!(ans.empty() && digit == 0)) {
                ans += to_string(digit);
            }
        }
        return ans.empty() ? "0" : ans;
    }
};

// class Solution {
// public:
//     string multiply(string num1, string num2) {
//         long n1 = 0, n2 = 0;
//         for (int i = 0; i < num1.length() ; i++) {
//             n1 = n1*10 + (num1[i] - '0');
//         }
//         for (int i = 0; i < num2.length() ; i++) {
//             n2 = n2*10 + (num2[i] - '0');
//         }
//         return to_string(n1*n2);
//     }
// };