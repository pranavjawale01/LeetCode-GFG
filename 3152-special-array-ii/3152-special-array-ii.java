class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int n = nums.length;
        int m = queries.length;

        int[] cumSum = new int[n];
        cumSum[0] = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                cumSum[i] = cumSum[i - 1] + 1;
            } else {
                cumSum[i] = cumSum[i - 1];
            }
        }

        boolean[] result = new boolean[m];
        int i = 0;
        for (int[] query : queries) {
            int start = query[0];
            int end = query[1];

            result[i] = cumSum[end] - cumSum[start] == 0;
            i++;
        }

        return result;
    }
}




// class Solution {
//     public boolean[] isArraySpecial(int[] nums, int[][] queries) {
//         int n = nums.length;
//         int m = queries.length;

//         int[] cumSum = new int[n];
//         cumSum[0] = 0;

//         for (int i = 1; i < n; i++) {
//             if (nums[i] % 2 == nums[i - 1] % 2) {
//                 cumSum[i] = cumSum[i - 1] + 1;
//             } else {
//                 cumSum[i] = cumSum[i - 1];
//             }
//         }

//         boolean[] result = new boolean[m];
//         int i = 0;
//         for (int[] query : queries) {
//             int start = query[0];
//             int end = query[1];

//             result[i] = cumSum[end] - cumSum[start] == 0;
//             i++;
//         }

//         return result;
//     }
// }