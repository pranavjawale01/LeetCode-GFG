class Solution {
    public int maxDistinctElements(int[] nums, int k) {
        Arrays.sort(nums);
        Set<Integer> st = new HashSet<>();
        int back = -k;
        int n = nums.length;
        
        for (int i = 0; i < n; i++) {
            int temp = Math.max(back + 1, nums[i] - k);
            if (temp <= nums[i] + k) {
                st.add(temp);
                back = temp;
            }
        }
        
        return st.size();
    }
}