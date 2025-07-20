class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int[] ans = new int[n];
        int cumVal = 0, cumSum = 0;

        for (int i = 0; i < n; i++) {
            ans[i] = cumSum;
            cumVal += boxes.charAt(i) == '0' ? 0 : 1;
            cumSum += cumVal;
        }

        cumVal = cumSum = 0;

        for (int i = n - 1; i >= 0; i--) {
            ans[i] += cumSum;
            cumVal += boxes.charAt(i) == '0' ? 0 : 1;
            cumSum += cumVal;
        }

        return ans;
    }
}







// class Solution {
//     public int[] minOperations(String boxes) {
//         int n = boxes.length();
//         int[] ans = new int[n];
//         for (int i = 0; i < n; i++) {
//             if (boxes.charAt(i) == '1') {
//                 for (int j = 0; j < n; j++) {
//                     ans[j] += Math.abs(j - i);
//                 }
//             }
//         }
//         return ans;
//     }
// }