class Solution {
    public String kthDistinct(String[] arr, int k) {
        Map<String, Integer> mp = new HashMap<>();
        for (String x : arr) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }
        for (String x : arr) {
            if (mp.get(x) == 1) {
                k--;
                if (k == 0) {
                    return x;
                }
            }
        }
        return "";
    }
}