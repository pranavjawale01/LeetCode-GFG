class Solution {
    private boolean solve(List<Integer> vi, int sp, int ep) {
        int l = 0, r = vi.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (vi.get(mid) < sp) {
                l = mid + 1;
            } else if (vi.get(mid) > ep) {
                r = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }

    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int m = queries.length, n = nums.length;
        List<Integer> vi = new ArrayList<>();
        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                vi.add(i);
            }
        }

        boolean[] ans = new boolean[m];
        for (int i = 0; i < m; i++) {
            int s = queries[i][0], e = queries[i][1];
            if (!solve(vi, s + 1, e)) {
                ans[i] = true;
            }
        }
        return ans;
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




// // class Solution {
// //     public boolean[] isArraySpecial(int[] nums, int[][] queries) {
// //         int n = nums.length;
// //         int m = queries.length;

// //         int[] cumSum = new int[n];
// //         cumSum[0] = 0;

// //         for (int i = 1; i < n; i++) {
// //             if (nums[i] % 2 == nums[i - 1] % 2) {
// //                 cumSum[i] = cumSum[i - 1] + 1;
// //             } else {
// //                 cumSum[i] = cumSum[i - 1];
// //             }
// //         }

// //         boolean[] result = new boolean[m];
// //         int i = 0;
// //         for (int[] query : queries) {
// //             int start = query[0];
// //             int end = query[1];

// //             result[i] = cumSum[end] - cumSum[start] == 0;
// //             i++;
// //         }

// //         return result;
// //     }
// // }