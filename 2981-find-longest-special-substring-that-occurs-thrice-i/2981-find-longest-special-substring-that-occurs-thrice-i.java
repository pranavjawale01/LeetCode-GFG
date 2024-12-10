class Solution {
    public int maximumLength(String s) {
        int n = s.length();
        Map<String, Integer> mp = new HashMap<>();
        int maxlen = -1;
        for (int i = 0; i < n; i++) {
            int len = 0;
            char curr = s.charAt(i);
            for (int j = i; j < n && s.charAt(j) == curr; j++) {
                len++;
                String key = curr + "," + len;
                mp.put(key, mp.getOrDefault(key, 0) + 1);
            }
        }
        for (Map.Entry<String, Integer> entry : mp.entrySet()) {
            if (entry.getValue() >= 3) {
                int len = Integer.parseInt(entry.getKey().split(",")[1]);
                maxlen = Math.max(maxlen, len);
            }
        }
        return maxlen == 0 ? -1 : maxlen;
    }
}