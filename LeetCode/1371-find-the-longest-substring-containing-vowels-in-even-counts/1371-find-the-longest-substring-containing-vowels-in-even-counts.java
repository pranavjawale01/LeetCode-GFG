class Solution {
    public int findTheLongestSubstring(String s) {
        Map<Integer, Integer> mp = new HashMap<>();
        int mask = 0;
        mp.put(mask, -1);
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'a') mask = mask ^ (1 << 0);
            else if (s.charAt(i) == 'e') mask = mask ^ (1 << 1);
            else if (s.charAt(i) == 'i') mask = mask ^ (1 << 2);
            else if (s.charAt(i) == 'o') mask = mask ^ (1 << 3);
            else if (s.charAt(i) == 'u') mask = mask ^ (1 << 4);

            if (mp.containsKey(mask)) {
                ans = Math.max(ans, i - mp.get(mask));
            } else {
                mp.put(mask, i);
            }
        }

        return ans;
    }
}



// class Solution {
//     public int findTheLongestSubstring(String s) {
//         Map<String, Integer> mp = new HashMap<>();
//         int[] state = new int[5];
//         String currState = "00000";
//         mp.put(currState, -1);
//         int ans = 0;

//         for (int i = 0; i < s.length(); i++) {
//             if (s.charAt(i) == 'a') state[0] = (state[0] + 1) % 2;
//             else if (s.charAt(i) == 'e') state[1] = (state[1] + 1) % 2;
//             else if (s.charAt(i) == 'i') state[2] = (state[2] + 1) % 2;
//             else if (s.charAt(i) == 'o') state[3] = (state[3] + 1) % 2;
//             else if (s.charAt(i) == 'u') state[4] = (state[4] + 1) % 2;

//             currState = "";
//             for (int j = 0; j < 5; j++) {
//                 currState += state[j];
//             }

//             if (mp.containsKey(currState)) {
//                 ans = Math.max(ans, i - mp.get(currState));
//             } else {
//                 mp.put(currState, i);
//             }
//         }

//         return ans;
//     }
// }