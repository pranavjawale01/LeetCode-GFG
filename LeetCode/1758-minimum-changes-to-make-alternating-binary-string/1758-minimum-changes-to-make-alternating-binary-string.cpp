class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int count0 = 0;
        int count1 = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] != '0' + i % 2) {
                count0++;
            } else {
                count1++;
            }
        }

        return min(count0, count1);
    }
};