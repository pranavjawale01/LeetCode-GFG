class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if (k == 0) {
            return vector<int>(n, 0);
        }
        vector<int> extendedCode = code;
        extendedCode.insert(extendedCode.end(), code.begin(), code.end());
        vector<int> result(n, 0);
        if (k > 0) {
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 1; j <= k; j++) {
                    sum += extendedCode[i + j];
                }
                result[i] = sum;
            }
        } else {
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 1; j <= -k; j++) {
                    sum += extendedCode[i + n - j];
                }
                result[i] = sum;
            }
        }
        return result;
    }
};