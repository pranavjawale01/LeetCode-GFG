class Solution {
public:
    void solve(int curr, int n, vector<int> &ans) {
        if (curr > n) {
            return;
        }
        ans.push_back(curr);
        for (int next = 0; next < 10; next++) {
            int nextnum = curr * 10 + next;
            if (nextnum > n) {
                return;
            }
            solve(nextnum, n, ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int num = 1; num < 10; num++) {
            solve(num, n, ans);
        }
        return ans;
    }
};






// class Solution {
// public:
//     vector<int> lexicalOrder(int n) {
//         vector<int> ans;
//         for (int i = 1; i <= n; i++) {
//             ans.push_back(i);
//         }
//         sort(ans.begin(), ans.end(), [](int a, int b) {
//             return to_string(a) < to_string(b);
//         });
//         return ans;
//     }
// };