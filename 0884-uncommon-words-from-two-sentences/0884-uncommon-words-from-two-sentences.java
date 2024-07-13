class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        Map<String, Integer> mp = new HashMap<>();
        String[] w1 = s1.split(" ");
        String[] w2 = s2.split(" ");
        for (String x : w1) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }
        for (String x : w2) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }
        List<String> ans = new ArrayList<>();
        for (Map.Entry<String, Integer> x : mp.entrySet()) {
            if (x.getValue() == 1) {
                ans.add(x.getKey());
            }
        }        
        return ans.toArray(new String[0]);
    }
}