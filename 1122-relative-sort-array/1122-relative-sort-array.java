class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        for (int x : arr1) {
            mp.put(x, mp.getOrDefault(x, 0) + 1);
        }
        List<Integer> ans = new ArrayList<>();
        for (int x : arr2) {
            while (mp.get(x) > 0) {
                ans.add(x);
                mp.put(x, mp.get(x) - 1);
            }
            mp.remove(x);
        }
        for (Map.Entry<Integer, Integer> x : mp.entrySet()) {
            int key = x.getKey();
            int value = x.getValue();
            while (value > 0) {
                ans.add(key);
                value--;
            }
        }
        int result = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            result[i] = ans.get(i);
        }
        return result;
    }
}