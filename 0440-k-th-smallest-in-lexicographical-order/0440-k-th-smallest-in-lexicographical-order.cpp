class Solution {
public:
    int count = 0;
    int result = 0;

    bool solve(long long curr, int n, int k) {
        if (curr > n) {
            return false;
        }
        count++;
        if (count == k) {
            result = curr;
            return true;
        }
        for (int digit = 0; digit <= 9; digit++) {
            long long nextnum = curr * 10 + digit;
            if (nextnum > n) {
                break;
            }
            if (solve(nextnum, n, k)) {
                return true;
            }
        }
        return false;
    }

    int findKthNumber(int n, int k) {
        for (long long num = 1; num <= 9; num++) {
            if (solve(num, n, k)) {
                break;
            }
        }
        return result;
    }
};





// MLE
// class Solution {
// public:
//     void solve(int curr, int n, vector<int> &ans) {
//         if (curr > n) {
//             return;
//         }
//         ans.push_back(curr);
//         for (int digit = 0; digit < 10; digit++) {
//             int nextnum = curr * 10 + digit;
//             if (nextnum > n) {
//                 return;
//             }
//             solve(nextnum, n, ans);
//         }
//     }
//     int findKthNumber(int n, int k) {
//         vector<int> ans;
//         for (int i = 1; i <= 9; i++) {
//             solve(i, n, ans);
//         }
//         return ans[k-1];
//     }
// };