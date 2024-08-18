class Solution {
public:
    unordered_map<int, bool> mp;
    bool isUgly(int n) {
        if (n <= 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        if (mp.find(n) != mp.end()) {
            return mp[n];
        }
        if (n % 2 == 0 && isUgly(n / 2)) {
            return mp[n] = true;
        }
        if (n % 3 == 0 && isUgly(n / 3)) {
            return mp[n] = true;
        }
        if (n % 5 == 0 && isUgly(n / 5)) {
            return mp[n] = true;
        }
        return mp[n] = false;
    }
    int nthUglyNumber(int n) {
        mp.clear();
        int num = 1;
        while (n > 0) {
            if (isUgly(num)) {
                n--;
            }
            num++;
        }
        return num - 1;
    }
};