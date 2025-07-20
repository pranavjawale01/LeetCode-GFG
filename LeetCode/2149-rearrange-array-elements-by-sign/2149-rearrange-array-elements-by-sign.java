class Solution {
    public int[] rearrangeArray(int[] nums) {
        List<Integer> pos = new ArrayList<>();
        List<Integer> neg = new ArrayList<>();
        List<Integer> output = new ArrayList<>();
        int n = nums.length;
        
        for (int num : nums) {
            if (num > 0) {
                pos.add(num);
            } else {
                neg.add(num);
            }
        }
        
        for (int i = 0; i < n / 2; i++) {
            output.add(pos.get(i));
            output.add(neg.get(i));
        }
        
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            result[i] = output.get(i);
        }
        
        return result;
    }
}