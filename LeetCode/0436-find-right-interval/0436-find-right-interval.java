class Solution {
    public int binarySearch(List<int[]> vec, int end) {
        int low = 0, high = vec.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vec.get(mid)[0] >= end) {
                ans = vec.get(mid)[1];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    public int[] findRightInterval(int[][] intervals) {
        int n = intervals.length;
        List<int[]> vec = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            vec.add(new int[]{intervals[i][0], i});
        }
        Collections.sort(vec, Comparator.comparingInt(a -> a[0]));
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            ans[i] = binarySearch(vec, end);
        }
        return ans;
    }
}




// class Solution {
//     public int[] findRightInterval(int[][] intervals) {
//         TreeMap<Integer, Integer> mp = new TreeMap<>();
//         int n = intervals.length;
//         int[] ans = new int[n];
//         for (int i = 0; i < n; i++) {
//             mp.put(intervals[i][0], i);
//         }
//         for (int i = 0; i < n; i++) {
//             Integer key = mp.ceilingKey(intervals[i][1]);
//             ans[i] = (key == null) ? -1 : mp.get(key);            
//         }
//         return ans;
//     }
// }