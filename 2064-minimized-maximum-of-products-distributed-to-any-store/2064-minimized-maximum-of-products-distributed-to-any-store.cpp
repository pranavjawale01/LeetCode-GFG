class Solution {
public:
    bool possible(int x, vector<int> &quantities, int n) {
        for (int &a : quantities) {
            n -= (a + x - 1) / x; //ceil(a/x);
            if (n < 0) {
                return false;
            }
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = *max_element(quantities.begin(), quantities.end());
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (possible(mid, quantities, n)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};