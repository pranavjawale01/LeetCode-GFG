class Solution {
    public int minOperations(int[] nums, int k) {
        Set<Integer> st = new HashSet<>();
        int m = 101;
        for (int x : nums) {
            m = Math.min(m, x);
            st.add(x);
        }
        if (m < k) return -1;
        return st.size() + (m == k ? -1 : 0);
    }
}