class Solution {
    public int numberOfMatches(int n) {
        int count = 0;
        while (n != 1) {
            if (n % 2 != 0) {
                count++;
                n--;
            }
            n = n / 2;
            count += n;
        }
        return count;
    }
}