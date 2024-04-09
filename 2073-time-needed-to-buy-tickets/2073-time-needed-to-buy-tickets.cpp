class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int i = 0, time = 0;
        int n = tickets.size();
        while (tickets[k] > 0) {
            if (i >= n) {
                i = 0;
            }
            if (tickets[i] > 0) {
                tickets[i]--;
                time++;
            }
            i++;
        }
        return time;
    }
};

// class Solution {
// public:
//     int timeRequiredToBuy(vector<int>& tickets, int k) {
//         int maxVal = tickets[k];
//         int ans = 0;
//         int n = tickets.size();
//         for (int i = 0; i < n; i++) {
//             if (tickets[i] >= maxVal) {
//                 if (i <= k) {
//                     ans += maxVal;
//                 } else {
//                     ans += maxVal - 1;
//                 }
//             } else {
//                 ans += tickets[i];
//             }
//         }
//         return ans;
//     }
// };

// // class Solution {
// // public:
// //     int timeRequiredToBuy(vector<int>& tickets, int k) {
// //         int n = tickets.size();
// //         queue<int> q;
// //         for (int i = 0; i < n; i++) {
// //             q.push(i);
// //         }
// //         int time = 0;
// //         while (true) {
// //             if (tickets[k] == 0) {
// //                 break;
// //             }
// //             int curr = q.front();
// //             tickets[curr]--;
// //             time++;
// //             q.pop();
// //             if (tickets[curr] > 0) {
// //                 q.push(curr);
// //             }
// //         }
// //         return time;
// //     }
// // };