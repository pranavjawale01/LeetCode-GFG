class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for (string &x : details) {
            int age = x[11] - '0';
            age = age * 10 + x[12] - '0';
            if (age > 60) {
                count++;
            }
        }
        return count;
    }
};