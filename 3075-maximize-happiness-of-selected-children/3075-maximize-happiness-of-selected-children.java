class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        long sum = 0;
        int n = happiness.length;
        for (int i = n - 1, j = 0; i >=  n - k; i--, j++) {
            if (happiness[i] - j > 0) {
                sum += happiness[i] - j;
            } else {
                return sum;
            }
        }
        return sum;
    }
}