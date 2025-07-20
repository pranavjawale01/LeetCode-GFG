class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        long long i = 1, temp = 1;
        while (temp <= x) {
            i++;
            temp = i * i;
        }
        return static_cast<int>(i - 1);
    }
};