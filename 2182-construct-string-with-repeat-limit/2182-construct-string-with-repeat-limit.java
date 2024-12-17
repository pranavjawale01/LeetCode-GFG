class Solution {
    public String repeatLimitedString(String s, int repeatLimit) {
        int[] count = new int[26];
        for (char ch : s.toCharArray()) {
            count[ch - 'a']++;
        }

        PriorityQueue<Character> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                pq.add((char) ('a' + i));
            }
        }

        StringBuilder result = new StringBuilder();
        while (!pq.isEmpty()) {
            char ch = pq.poll();

            int freq = Math.min(count[ch - 'a'], repeatLimit);
            for (int k = 0; k < freq; k++) {
                result.append(ch);
            }
            count[ch - 'a'] -= freq;

            if (count[ch - 'a'] > 0 && !pq.isEmpty()) {
                char nextChar = pq.poll();

                result.append(nextChar);
                count[nextChar - 'a']--;

                if (count[nextChar - 'a'] > 0) {
                    pq.add(nextChar);
                }
                pq.add(ch);
            }
        }
        return result.toString();
    }
}










// class Solution {
//     public String repeatLimitedString(String s, int repeatLimit) {
//         int[] count = new int[26];
//         for (char ch : s.toCharArray()) {
//             count[ch - 'a']++;
//         }

//         StringBuilder result = new StringBuilder();
//         int i = 25;

//         while (i >= 0) {
//             if (count[i] == 0) {
//                 i--;
//                 continue;
//             }

//             char ch = (char) ('a' + i);
//             int freq = Math.min(count[i], repeatLimit);

//             for (int k = 0; k < freq; k++) {
//                 result.append(ch);
//             }
//             count[i] -= freq;

//             if (count[i] > 0) {
//                 int j = i - 1;
//                 while (j >= 0 && count[j] == 0) {
//                     j--;
//                 }

//                 if (j < 0) {
//                     break;
//                 }

//                 result.append((char) ('a' + j));
//                 count[j]--;
//             }
//         }
//         return result.toString();
//     }
// }