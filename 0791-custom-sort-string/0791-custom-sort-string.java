class Solution {
    public String customSortString(String order, String s) {
        Map<Character, Integer> mp = new HashMap<>();
        for (char ch : s.toCharArray()) {
            mp.put(ch, mp.getOrDefault(ch, 0) + 1);
        }
        StringBuilder ans = new StringBuilder();
        for (char ch : order.toCharArray()) {
            if (mp.containsKey(ch)) {
                int count = mp.get(ch);
                while (count > 0) {
                    ans.append(ch);
                    count--;
                }
                mp.remove(ch);
            }
        }
        for (Map.Entry<Character, Integer> entry : mp.entrySet()) {
            char ch = entry.getKey();
            int count = entry.getValue();
            while (count > 0) {
                ans.append(ch);
                count--;
            }
        }
        return ans.toString();
    }
}