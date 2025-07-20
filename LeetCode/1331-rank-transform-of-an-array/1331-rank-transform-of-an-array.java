class Solution {
    public int[] arrayRankTransform(int[] arr) {
        Set<Integer> st = new TreeSet<>();
        for (int x : arr) st.add(x);
        int rank = 1;
        Map<Integer, Integer> mp = new HashMap<>();
        for (int x : st) {
            mp.put(x, rank);
            rank++;
        }
        for (int i = 0; i < arr.length; i++) {
            arr[i] = mp.get(arr[i]);
        }
        return arr;
    }
}