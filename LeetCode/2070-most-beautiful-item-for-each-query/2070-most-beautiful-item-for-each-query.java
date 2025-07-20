class Solution {
    public int customBinarySearch(List<int[]> items, int queryPrice) {
        int l = 0, r = items.size() - 1;
        int maxBeauty = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (items.get(mid)[0] > queryPrice) {
                r = mid - 1;
            } else {
                maxBeauty = Math.max(maxBeauty, items.get(mid)[1]);
                l = mid + 1;
            }
        }
        return maxBeauty;
    }
    public int[] maximumBeauty(int[][] items, int[] queries) {
        Arrays.sort(items, Comparator.comparingInt(a -> a[0]));
        int n = items.length, m = queries.length;
        int[] ans = new int[m];
        int maxBeautySeen = items[0][1];
        for (int i = 1; i < n; i++) {
            maxBeautySeen = Math.max(maxBeautySeen, items[i][1]);
            items[i][1] = maxBeautySeen;
        }
        List<int[]> itemList = Arrays.asList(items);
        for (int i = 0; i < m; i++) {
            ans[i] = customBinarySearch(itemList, queries[i]);
        }
        return ans;
    }
}