class Solution {
    public int countCompleteDayPairs(int[] hours) {
        Map<Integer, Integer> mp = new HashMap<>();
        int count = 0;
        for (int hour : hours) {
            int mod = hour % 24;
            int com = (24 - mod) % 24;
            if (mp.containsKey(com)) {
                count += mp.get(com);
            }
            mp.put(mod, mp.getOrDefault(mod, 0) + 1);
        }
        return count;
    }
}



// class Solution {
//     public int countCompleteDayPairs(int[] hours) {
//         int n = hours.length;
//         int count = 0;
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if ((hours[i] + hours[j]) % 24 == 0) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// }