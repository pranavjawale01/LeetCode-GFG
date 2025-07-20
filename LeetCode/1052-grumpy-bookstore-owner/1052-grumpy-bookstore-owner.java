class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int maxUnSat = 0;
        int curUnSat = 0;
        int n = grumpy.length;
        for (int i = 0; i < minutes; i++) {
            curUnSat += customers[i] * grumpy[i];
        }
        maxUnSat = curUnSat;
        int i = 0, j = minutes;
        while (j < n) {
            curUnSat += customers[j] * grumpy[j];
            curUnSat -= customers[i] * grumpy[i];
            maxUnSat = Math.max(maxUnSat, curUnSat);
            i++;
            j++;
        }
        int totalSat = maxUnSat;
        for (int k = 0; k < n; k++) {
            totalSat += customers[k] * (1 - grumpy[k]);
        }
        return totalSat;
    }
}




// class Solution {
//     public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
//         int n = grumpy.length;
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             if (grumpy[i] == 0) {
//                 ans += customers[i];
//             }
//         }
//         int temp1 = ans;
//         for (int i = 0; i <= n - minutes; i++) {
//             int temp = temp1;
//             for (int j = i; j < i + minutes; j++) {
//                 if (grumpy[j] == 1) {
//                     temp += customers[j];
//                 }
//             }
//             ans = Math.max(ans, temp);
//         }
//         return ans;
//     }
// }