class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int zero = 0;
        int one = 0;
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            if(s[i] - '0' == 0) zero++;
            else one++;

            int localZero = zero;
            int localOne = one;
            for (int j = 0; j <= i; j++) {

                if(min(localZero, localOne) <= k) count++;

                if(s[j] - '0' == 0) localZero--;
                else localOne--;
            }
        }
        return count;  
    }
};