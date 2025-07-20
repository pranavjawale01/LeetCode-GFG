class Solution {
public:
    int numberOfChild(int n, int k) {
        n--;
        int rounds  = k / n;
        int rem = k % n;
        if (rounds % 2 == 0) {
            return rem;
        } else {
            return n - rem;
        }
    }
};


// class Solution {
// public:
//     int numberOfChild(int n, int k) {
//         int i = 0;
//         bool flag= true;
//         while (k > 0) {
//             if (i == n - 1) {
//                 flag = false;
//             } else if (i == 0) {
//                 flag = true;
//             }
//             if (flag) {
//                 i++;
//             } else {
//                 i--;
//             }
//             k--;
//         }
//         return i;
//     }
// };