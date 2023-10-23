class Solution {
    public boolean isPowerOfFour(int n) {
        if(n==0)
        {
            return false;
        }
        else if(n==1)
        {
            return true;
        }
        return n%4==0 && isPowerOfFour(n/4);
    }
}