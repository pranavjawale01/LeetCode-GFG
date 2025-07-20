class Solution {

    class SegmentTree {
        int[] st;
        int[] lazy;
        int n;

        public SegmentTree(int n) {
            this.n = n;
            st = new int[4 * n];
            lazy = new int[4 * n];
            Arrays.fill(lazy, -1);
            buildTree(0, 0, n-1);
        }

        private void buildTree(int i, int low, int high) {
            if (low == high) {
                st[i] = low == 0 ? 0 : 1;
                return;
            }
            int mid = low + (high - low) / 2;
            buildTree(2*i + 1, low, mid);
            buildTree(2*i + 2, mid+1, high);
            st[i] = st[2*i + 1] + st[2*i + 2];
        }

        public int query() {
            return st[0];
        }

        public void update(int left, int right) {
            update(0, 0, n-1, left, right);
        }

        private void propagate(int i, int low, int high) {
            if (lazy[i] != -1) {
                st[i] = 0;
                if (low != high) {
                    lazy[2*i + 1] = lazy[i];
                    lazy[2*i + 2] = lazy[i];
                }
                lazy[i] = -1;
            }
        }

        private void update(int i, int low, int high, int left, int right) {
            propagate(i, low, high);
            if (low > right || high < left) {
                return;
            }
            if (low >= left && high <= right) {
                st[i] = 0;
                if (low != high) {
                    lazy[2*i + 1] = 0;
                    lazy[2*i + 2] = 0;
                }
                return;
            }
            int mid = low + (high - low) / 2;
            update(2*i + 1, low, mid, left, right);
            update(2*i + 2, mid+1, high, left, right);
            st[i] = st[2 * i + 1] + st[2 * i + 2];
        }
    }

    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        SegmentTree seg = new SegmentTree(n);
        List<Integer> ans = new ArrayList<>();
        for (int[] query : queries) {
            int u = query[0];
            int v = query[1];
            seg.update(u + 1, v - 1);
            ans.add(seg.query());
        }
        return ans.stream().mapToInt(i -> i).toArray();
    }
}










// class Solution {
//     public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
//         TreeSet<Integer> st = new TreeSet<>();
//         for (int i = 0; i < n; i++) {
//             st.add(i);
//         }
//         List<Integer> ans = new ArrayList<>();
//         for (int[] query : queries) {
//             Integer a = st.ceiling(query[0] + 1);
//             Integer b = st.floor(query[1] - 1);
//             if (a != null && b != null && a <= b) {
//                 st.subSet(a, b + 1).clear();
//             }
//             ans.add(st.size() - 1);
//         }
//         return ans.stream().mapToInt(Integer::intValue).toArray();
//     }
// }









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