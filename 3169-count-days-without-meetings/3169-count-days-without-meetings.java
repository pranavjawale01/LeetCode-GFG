class Solution {
    public int countDays(int days, int[][] meetings) {
        Arrays.sort(meetings, Comparator.comparingInt(a -> a[0]));
        int lastDay = 0;
        int dayWithoutMeeting = 0;
        for (int[] meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            dayWithoutMeeting += Math.max(0, start - lastDay - 1);
            lastDay = Math.max(lastDay, end);
        }
        dayWithoutMeeting += Math.max(0, days - lastDay);
        return dayWithoutMeeting;
    }
}