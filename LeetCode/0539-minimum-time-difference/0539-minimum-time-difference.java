class Solution {
    public int toMinutes(String time) {
        int hours = Integer.parseInt(time.substring(0, 2));
        int mins = Integer.parseInt(time.substring(3, 5));
        return hours * 60 + mins;
    }

    public int findMinDifference(List<String> timePoints) {
        int n = timePoints.size();
        if (n > 1440) {
            return 0;
        }

        Collections.sort(timePoints);

        int ans = Integer.MAX_VALUE;

        for (int i = 0; i < n - 1; i++) {
            int time1 = toMinutes(timePoints.get(i));
            int time2 = toMinutes(timePoints.get(i + 1));
            ans = Math.min(ans, time2 - time1);
        }

        int firstTime = toMinutes(timePoints.get(0));
        int lastTime = toMinutes(timePoints.get(n - 1));

        ans = Math.min(ans, firstTime + 1440 - lastTime);

        return ans;
    }
}