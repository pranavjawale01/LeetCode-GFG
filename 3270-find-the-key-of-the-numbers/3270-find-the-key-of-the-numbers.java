class Solution {
    private String solve(int n) {
        return String.format("%04d", n);
    }

    public int generateKey(int num1, int num2, int num3) {
        String s1 = solve(num1);
        String s2 = solve(num2);
        String s3 = solve(num3);
        int ans = 0;

        for (int i = 0; i < 4; i++) {
            ans = ans * 10 + Math.min(s1.charAt(i), Math.min(s2.charAt(i), s3.charAt(i))) - '0';
        }

        return ans;
    }
}