class Solution {
    public String customSortString(String order, String s) {
        int[] arr = new int[26];
        Arrays.fill(arr , -1);
        for (int i = 0; i < order.length(); i++) {
            char ch = order.charAt(i);
            arr[ch - 'a'] = i;
        }
        Comparator<Character> myComparator = (ch1, ch2) -> arr[ch1 - 'a'] - arr[ch2 - 'a'];
        Character[] sChar = new Character[s.length()];
        for (int i = 0; i < s.length(); i++) {
            sChar[i] = s.charAt(i);
        }
        Arrays.sort(sChar, myComparator);
        StringBuilder ans = new StringBuilder();
        for (char ch : sChar) {
            ans.append(ch);
        }
        return ans.toString();
    }
}
// class Solution {
//     public String customSortString(String order, String s) {
//         Map<Character, Integer> mp = new HashMap<>();
//         for (char ch : s.toCharArray()) {
//             mp.put(ch, mp.getOrDefault(ch, 0) + 1);
//         }
//         StringBuilder ans = new StringBuilder();
//         for (char ch : order.toCharArray()) {
//             if (mp.containsKey(ch)) {
//                 int count = mp.get(ch);
//                 while (count > 0) {
//                     ans.append(ch);
//                     count--;
//                 }
//                 mp.remove(ch);
//             }
//         }
//         for (Map.Entry<Character, Integer> entry : mp.entrySet()) {
//             char ch = entry.getKey();
//             int count = entry.getValue();
//             while (count > 0) {
//                 ans.append(ch);
//                 count--;
//             }
//         }
//         return ans.toString();
//     }
// }