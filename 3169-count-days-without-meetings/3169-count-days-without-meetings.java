class Solution {
    public int countDays(int days, int[][] meetings) {
        Arrays.sort(meetings, Comparator.comparingInt(a -> a[0]));
        ArrayList<ArrayList<Integer>> merge = new ArrayList<>();
        for (int[] meeting : meetings) {
            if (merge.isEmpty() || merge.get(merge.size() - 1).get(1) < meeting[0]) {
                merge.add(new ArrayList<>(Arrays.asList(meeting[0], meeting[1])));
            } else {
                merge.get(merge.size() - 1).set(1, Math.max(merge.get(merge.size() - 1).get(1), meeting[1]));
            }
        }
        int day = 0;
        if (merge.get(0).get(0) > 1) {
            day += merge.get(0).get(0) - 1;
        }
        for (int i = 1; i < merge.size(); i++) {
            day += merge.get(i).get(0) - merge.get(i - 1).get(1) - 1;
        }
        if (merge.get(merge.size() - 1).get(1) < days) {
            day += days - merge.get(merge.size() - 1).get(1);
        }
        return day;
    }
}


// class Solution {
//     public int countDays(int days, int[][] meetings) {
//         Arrays.sort(meetings, Comparator.comparingInt(a -> a[0]));
//         int lastDay = 0;
//         int dayWithoutMeeting = 0;
//         for (int[] meeting : meetings) {
//             int start = meeting[0];
//             int end = meeting[1];
//             dayWithoutMeeting += Math.max(0, start - lastDay - 1);
//             lastDay = Math.max(lastDay, end);
//         }
//         dayWithoutMeeting += Math.max(0, days - lastDay);
//         return dayWithoutMeeting;
//     }
// }