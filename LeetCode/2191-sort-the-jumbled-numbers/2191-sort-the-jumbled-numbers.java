class Solution {
    private int mapValue(int num, int[] mapping) {
        if (num == 0) {
            return mapping[0];
        }
        int ans = 0, place = 1;
        while (num > 0) {
            ans += mapping[num % 10] * place;
            place *= 10;
            num /= 10;
        }
        return ans;
    }
    public int[] sortJumbled(int[] mapping, int[] nums) {
        int n = nums.length;
        int[][] mappedNums = new int[n][2];

        for (int i = 0; i < n; i++) {
            mappedNums[i][0] = mapValue(nums[i], mapping);
            mappedNums[i][1] = nums[i];
        }

        Arrays.sort(mappedNums, (a, b) -> Integer.compare(a[0], b[0]));
        int[] sortedNums = new int[n];
        for (int i = 0; i < n; i++) {
            sortedNums[i] = mappedNums[i][1];
        }

        return sortedNums;
    }
}