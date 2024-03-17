class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int n = intervals.length;
        int[][] temp = new int[n + 1][2];
        for (int i = 0; i < n; i++) {
            temp[i][0] = intervals[i][0];
            temp[i][1] = intervals[i][1];
        }
        temp[n][0] = newInterval[0];
        temp[n][1] = newInterval[1];

        Comparator<int[]> comparator = new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return Integer.compare(a[0], b[0]);
            }
        };

        Arrays.sort(temp, comparator);

        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (temp[count][1] >= temp[i][0]) {
                temp[count][1] = Math.max(temp[i][1], temp[count][1]);
            } else {
                count++;
                temp[count][0] = temp[i][0];
                temp[count][1] = temp[i][1];
            }
        }

        int[][] result = new int[count + 1][2];
        for (int i = 0; i <= count; i++) {
            result[i][0] = temp[i][0];
            result[i][1] = temp[i][1];
        }

        return result;
    }
}