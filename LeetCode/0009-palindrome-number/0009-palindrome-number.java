class Solution {
    public boolean isPalindrome(int x) {
        if(x<0) {
            return false;
        }
        long original = x, reverse = 0, y = 0;
        while(x>0) {
            y = x % 10;
            reverse = reverse*10 + y;
            x /= 10;
        }
        return reverse == original;
    }
}