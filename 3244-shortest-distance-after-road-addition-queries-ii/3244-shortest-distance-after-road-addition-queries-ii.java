class Solution {
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        TreeSet<Integer> st = new TreeSet<>();
        for (int i = 0; i < n; i++) {
            st.add(i);
        }
        List<Integer> ans = new ArrayList<>();
        for (int[] query : queries) {
            Integer a = st.ceiling(query[0] + 1);
            Integer b = st.floor(query[1] - 1);
            if (a != null && b != null && a <= b) {
                st.subSet(a, b + 1).clear();
            }
            ans.add(st.size() - 1);
        }
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}









// class Solution {
//     private int findLowerBound(List<Integer> list, int val) {
//         int low = 0, high = list.size();
//         while (low < high) {
//             int mid = low + (high - low) / 2;
//             if (list.get(mid) > val) {
//                 high = mid;
//             } else {
//                 low = mid + 1;
//             }
//         }
//         return low < list.size() ? low : -1;
//     }

//     private int findUpperBound(List<Integer> list, int val) {
//         int low = 0, high = list.size();
//         while (low < high) {
//             int mid = low + (high - low) / 2;
//             if (list.get(mid) <= val) {
//                 low = mid + 1;
//             } else {
//                 high = mid;
//             }
//         }
//         return low > 0 ? low - 1 : -1;
//     }

//     public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
//         List<Integer> st = new ArrayList<>();
//         for (int i = 0; i < n; i++) {
//             st.add(i);
//         }
//         int[] ans = new int[queries.length];
//         int i = 0;
//         for (int[] x : queries) {
//             int a = x[0];
//             int b = x[1];
//             int low = findLowerBound(st, a + 1);
//             int high = findUpperBound(st, b - 1);
//             if (low != -1 && high != -1 && low <= high) {
//                 st.subList(low, high + 1).clear();
//             }
//             ans[i] = st.size() - 1;
//             i++;
//         }
//         return ans;
//     }
// }