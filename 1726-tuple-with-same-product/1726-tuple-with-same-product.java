class Solution {
    public int tupleSameProduct(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length, count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                int val = nums[i] * nums[j];
                Set<Integer> st = new HashSet<>();
                for (int k = i + 1; k < j; k++) {
                    if (val % nums[k] == 0) {
                        int data = val / nums[k];
                        if (st.contains(data)) {
                            count++;
                        }
                        st.add(nums[k]);
                    }
                }
            }
        }
        return count * 8;
    }
}