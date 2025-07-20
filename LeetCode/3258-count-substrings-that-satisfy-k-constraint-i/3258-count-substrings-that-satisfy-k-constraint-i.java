class Solution {
    public int countKConstraintSubstrings(String s, int k) {
        int zero = 0;
        int one = 0;
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i) - '0' == 0) zero++;
            else one++;

            int localZero = zero;
            int localOne = one;
            for (int j = 0; j <= i; j++) {

                if(Math.min(localZero, localOne) <= k) count++;

                if(s.charAt(j) - '0' == 0) localZero--;
                else localOne--;
            }
        }
        return count;  
    }
}