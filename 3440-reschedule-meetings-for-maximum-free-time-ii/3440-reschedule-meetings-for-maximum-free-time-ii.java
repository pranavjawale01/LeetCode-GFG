class Solution {
    public int maxFreeTime(int eventTime, int[] startTime, int[] endTime) {
        int n = startTime.length;
        int[] diff = new int[n + 1];
        
        diff[0] = startTime[0];
        for (int i = 1; i < n; i++) {
            diff[i] = startTime[i] - endTime[i - 1];
        }
        diff[n] = eventTime - endTime[n - 1];
        
        int m = diff.length;
        int[] suffix = new int[m];
        int[] prefix = new int[m];
        
        for (int i = m - 2; i >= 0; i--) {
            suffix[i] = Math.max(suffix[i + 1], diff[i + 1]);
        }
        
        for (int i = 2; i < m; i++) {
            prefix[i] = Math.max(prefix[i - 1], diff[i - 2]);
        }
        
        int ans = 0;
        for (int i = 1; i < m; i++) {
            int meetingTime = endTime[i - 1] - startTime[i - 1];
            if (meetingTime <= Math.max(prefix[i], suffix[i])) {
                ans = Math.max(ans, diff[i - 1] + diff[i] + meetingTime);
            }
            ans = Math.max(ans, diff[i - 1] + diff[i]);
        }
        
        return ans;
    }
}