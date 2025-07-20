class Solution {
    public int longestPalindrome(String s) {
        int n = s.length();
        Map<Character, Integer> mp = new HashMap<>();
        int result = 0;
        int odd = 0;
        for (char c : s.toCharArray()) {
            mp.put(c, mp.getOrDefault(c, 0) + 1);
            if (mp.get(c) % 2 != 0) {
                odd++;
            } else {
                odd--;
            }
        }
        if (odd > 0) {
            return n - odd + 1;
        }
        return n;
    }
}



// class Solution {
//     public int longestPalindrome(String s) {
//         Map<Character, Integer> mp = new HashMap<>();
//         for (char c : s.toCharArray()) {
//             mp.put(c, mp.getOrDefault(c, 0) + 1);
//         }
//         int result = 0;
//         boolean odd = false;
//         for (Map.Entry<Character, Integer> x : mp.entrySet()) {
//             int count = x.getValue();
//             if (count % 2 == 0) {
//                 result += count;
//             } else {
//                 result += count - 1;
//                 odd = true;
//             }
//         }
//         if (odd) {
//             result++;
//         }
//         return result;
//     }
// }



// class Solution {
//     public int longestPalindrome(String s) {
//         Set<Character> st = new HashSet<>();
//         int result = 0;
//         for (char c : s.toCharArray()) {
//             if (st.contains(c)) {
//                 result += 2;
//                 st.remove(c);
//             } else {
//                 st.add(c);
//             }
//         }
//         if (!st.isEmpty()) {
//             result++;
//         }
//         return result;
//     }
// }