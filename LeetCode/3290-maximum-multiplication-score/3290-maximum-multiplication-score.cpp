using ll = long long;
class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int row = a.size(), col = b.size();
        vector<vector<ll>> mul(row, vector<ll>(col, LLONG_MIN));
        for (int j = 0; j < col; j++) {
            mul[0][j] = (ll)a[0]*b[j];
        }
        for (int i = 1; i < row; i++) {
            ll maxAns = LLONG_MIN;
            for (int j = i; j < col; j++) {
                maxAns = max(maxAns, mul[i - 1][j - 1]);
                mul[i][j] = maxAns + (ll)a[i]*b[j];
            }
        }
        ll res = LLONG_MIN;
        for (int j = 0; j < col; j++) {
            res = max(res, mul[3][j]);
        }
        return res;
    }
};