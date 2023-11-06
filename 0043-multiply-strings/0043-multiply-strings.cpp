class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        vector<int> result(len1 + len2, 0);

        for (int i = len1 - 1; i >= 0; --i) {
            for (int j = len2 - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        
        string res = "";
        for (int num : result) {
            res.push_back(num + '0');
        }

        auto it = res.begin();
        while (it != res.end() && *it == '0') {
            ++it;
        }

        return it == res.end() ? "0" : string(it, res.end());
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