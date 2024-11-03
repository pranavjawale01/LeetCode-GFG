class Solution {
public:
    bool isBalanced(string num) {
        int a = 0, b = 0;
        int n = num.size();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                a += num[i] - '0';
            } else {
                b += num[i] - '0';
            }
        }
        return a == b;
    }
};