class Solution {
    public int minimumPushes(String word) {
        int[] freq = new int[26];
        for (char c : word.toCharArray()) {
            freq[c - 'a']++;
        }
        Arrays.sort(freq);
        int ans = 0;
        for (int i = 25; i >= 0; i--) {
            ans += ((25 - i) / 8 + 1) * freq[i];
        }
        return ans;
    }
}





// class Solution {
//     public int minimumPushes(String word) {
//         HashMap<Integer, Integer> mp = new HashMap<>();
//         int key = 2;
//         int ans = 0;
//         for (char c : word.toCharArray()) {
//             if (key > 9) {
//                 key = 2;
//             }
//             mp.put(key, mp.getOrDefault(key, 0) + 1);
//             ans += mp.get(key);
//             key++;
//         }
//         return ans;
//     }
// }






// class Solution {
//     public int minimumPushes(String word) {
//         HashMap<Character, Integer> mp = new HashMap<>();
//         for (char c : word.toCharArray()) {
//             mp.put(c, mp.getOrDefault(c, 0) + 1);
//         }
//         int size = mp.size();
//         if (size <= 8) {
//             return word.length();
//         }
//         if (size > 8 && size < 17) {
//             return 8 + (size - 8) * 2;
//         }
//         if (size > 16 && size < 25) {
//             return 8 + 16 + (size - 16) * 3;
//         }
//         return 8 + 16 + 24 + (size - 24) * 4;
//     }
// }