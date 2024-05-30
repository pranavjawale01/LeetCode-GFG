class Solution {
    public int countTriplets(int[] arr) {
        int[] prefixXor = new int[arr.length + 1];
        prefixXor[0] = 0;
        for (int i = 1; i <= arr.length; i++) {
            prefixXor[i] = prefixXor[i-1] ^ arr[i-1];
        }
        int triplets = 0;
        for (int i = 0; i < prefixXor.length; i++) {
            for (int k = i + 1; k < prefixXor.length; k++) {
                if (prefixXor[k] == prefixXor[i]) {
                    triplets += k - i - 1;
                }
            }
        }
        return triplets;
    }
}


// class Solution {
//     public int countTriplets(int[] arr) {
//         int count = 0;
//         int n = arr.length;
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 int a = 0;
//                 for (int k = i; k < j; k++) {
//                     a ^= arr[k];
//                 } 
//                 int b = 0;
//                 for (int k = j; k < n; k++) {
//                     b ^= arr[k];
//                     if (a == b) {
//                         count++;
//                     }
//                 }
//             }
//         }
//         return count;
//     }
// }