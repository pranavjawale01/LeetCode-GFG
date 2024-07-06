class Solution {
    public int passThePillow(int n, int time) {
        int totalCycle = time / (n-1);
        int timeLeft = time % (n-1);
        if (totalCycle % 2 == 0) {
            return timeLeft + 1;
        }
        return n - timeLeft;
    }
}





// class Solution {
//     public int passThePillow(int n, int time) {
//         int idx = 1;
//         int dir = 1;
//         while (time > 0) {
//             if (idx + dir >= 1 && idx + dir <= n) {
//                 idx += dir;
//                 time--;
//             } else {
//                 dir *= -1;
//             }
//         }
//         return idx;
//     }
// }





// class Solution {
//     public int passThePillow(int n, int time) {
//         int cycleLength = (n - 1) * 2;
//         int positionInCycle = time % cycleLength;
//         if (positionInCycle < n) {
//             return positionInCycle + 1;
//         }
//         return 2 * n - positionInCycle - 1;
//     }
// }