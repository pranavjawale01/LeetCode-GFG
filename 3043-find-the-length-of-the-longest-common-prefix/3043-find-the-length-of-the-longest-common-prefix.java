class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        Set<Integer> st = new HashSet<>();
        
        for (int x : arr1) {
            int val = x;
            while (!st.contains(val) && val > 0) {
                st.add(val);
                val /= 10;
            }
        }

        int ans = 0;

        for (int x : arr2) {
            int num = x;
            while (!st.contains(num) && num > 0) {
                num /= 10;
            }
            if (num > 0) {
                ans = Math.max(ans, (int) Math.log10(num) + 1);
            }
        }
        
        return ans;
    }
}