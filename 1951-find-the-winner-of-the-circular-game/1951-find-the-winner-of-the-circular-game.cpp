class Solution {
public:
    int solve(int n, int k) {
        if (n == 1) {
            return 0;
        }
        int i = solve(n-1, k);
        i = (i + k) % n;
        return i;
    }
    int findTheWinner(int n, int k) {
        int ans = solve(n, k);
        return ans + 1;
    }
};





// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         queue<int> q;
//         for (int i = 0; i < n; i++) {
//             q.push(i+1);
//         }
//         while (q.size() > 1) {
//             for (int i = 1; i <= k-1; i++) {
//                 q.push(q.front());
//                 q.pop();
//             }
//             q.pop();
//         }
//         return q.front();
//     }
// };



// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         vector<int> arr;
//         for (int i = 0; i < n; i++) {
//             arr.push_back(i + 1);
//         }
//         int i = 0;
//         while (arr.size() > 1) {
//             i = (i + k - 1) % arr.size();
//             arr.erase(arr.begin() + i);
//         }
//         return arr[0];
//     }
// };