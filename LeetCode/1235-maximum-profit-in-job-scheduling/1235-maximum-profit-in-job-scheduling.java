class Solution {
    private int[] memo;
    private int n;

    private int getNextIndex(int[][] array, int l, int currentJobEnd) {
        int r = n - 1;
        int result = n + 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (array[mid][0] >= currentJobEnd) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }

    private int solve(int[][] array, int i) {
        if (i >= n)
            return 0;

        if (memo[i] != -1)
            return memo[i];

        int next = getNextIndex(array, i + 1, array[i][1]);

        int taken = array[i][2] + solve(array, next);
        int notTaken = solve(array, i + 1);

        return memo[i] = Math.max(taken, notTaken);
    }

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        n = startTime.length;

        memo = new int[n];
        Arrays.fill(memo, -1);

        int[][] array = new int[n][3];

        for (int i = 0; i < n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }

        Arrays.sort(array, (vec1, vec2) -> Integer.compare(vec1[0], vec2[0]));

        return solve(array, 0);
    }
}

// class Solution {
//     public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
//         int n = startTime.length;
//         int[][] jobs = new int[n][3];

//         for (int i = 0; i < n; i++) {
//             jobs[i] = new int[]{startTime[i], endTime[i], profit[i]};
//         }

//         Arrays.sort(jobs, (a, b) -> a[1] - b[1]);

//         TreeMap<Integer, Integer> dp = new TreeMap<>();
//         dp.put(0, 0);

//         for (int[] job : jobs) {
//             int val = job[2] + dp.floorEntry(job[0]).getValue();
//             if (val > dp.lastEntry().getValue()) {
//                 dp.put(job[1], val);
//             }
//         }

//         return dp.lastEntry().getValue();
//     }
// }