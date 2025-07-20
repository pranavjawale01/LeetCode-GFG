class Solution {
    public int[] minBitwiseArray(List<Integer> nums) {
        int n = nums.size();
        int[] arr = new int[n];
        Arrays.fill(arr, -1);
        for (int i = 0; i < n; i++) {
            int x = nums.get(i);
            for (int j = 0; j <= x; j++) {
                if ((j | (j + 1)) == x) {
                    arr[i] = j;
                    break;
                }
            }
        }
        return arr;
    }
}