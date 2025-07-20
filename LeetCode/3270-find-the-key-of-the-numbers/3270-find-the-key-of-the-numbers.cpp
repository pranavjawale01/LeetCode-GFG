class Solution {
public:
    string solve(int n) {
        if (n < 10) {
            return "000" + to_string(n);
        }
        if (n < 100) {
            return "00" + to_string(n);
        }
        if (n < 1000) {
            return "0" + to_string(n);
        }
        return to_string(n);
    }

    int generateKey(int num1, int num2, int num3) {
        string s1 = solve(num1);
        string s2 = solve(num2);
        string s3 = solve(num3);
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            ans = ans * 10 + (min({s1[i], s2[i], s3[i]}) - '0');
        }
        return ans;
    }
};