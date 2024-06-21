class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = grumpy.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                ans += customers[i];
            }
        }
        int temp1 = ans;
        for (int i = 0; i <= n - minutes; i++) {
            int temp = temp1;
            for (int j = i; j < i + minutes; j++) {
                if (grumpy[j] == 1) {
                    temp += customers[j];
                }
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};