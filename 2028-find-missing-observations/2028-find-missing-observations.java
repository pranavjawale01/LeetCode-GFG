class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int m = rolls.length;
        int sumRolls = 0;
        for (int roll : rolls) {
            sumRolls += roll;
        }
        
        int total = (n + m) * mean;
        int missSum = total - sumRolls;
        
        if (missSum < n || missSum > 6 * n) {
            return new int[0];
        }
        
        int baseValue = missSum / n;
        int remainder = missSum % n;
        
        int[] result = new int[n];
        Arrays.fill(result, baseValue);
        
        for (int i = 0; i < remainder; i++) {
            result[i]++;
        }
        
        return result;
    }
}