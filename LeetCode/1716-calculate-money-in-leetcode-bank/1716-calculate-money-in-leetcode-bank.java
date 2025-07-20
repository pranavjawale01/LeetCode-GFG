class Solution {
    public int totalMoney(int n) {
        int total = 0, week = 1;
        for (int i = 1; i <= n; i++) {
            total += week++;
            if (i % 7 == 0) {
                week = i / 7 + 1;
            }
        }
        return total;
    }
}