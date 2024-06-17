class Solution {
    private int binarySearch(List<Integer> dp, int x) {
        int left = 0, right = dp.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (dp.get(mid) <= x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
    public int[] longestObstacleCourseAtEachPosition(int[] obstacles) {
        int n = obstacles.length;
        List<Integer> dp = new ArrayList<>();
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            int temp = obstacles[i];
            if (dp.isEmpty() || temp >= dp.get(dp.size()-1)) {
                dp.add(temp);
                ans[i] = dp.size();
            } else {
                int idx  = binarySearch(dp, temp);
                dp.set(idx, temp);
                ans[i] = idx + 1;
            }
        }
        return ans;
    }
}