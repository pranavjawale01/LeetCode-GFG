class Solution {
    public int fib(int n) {
        if (n <= 1) {
            return n;
        }
        int first = 1;
        int second = 0;
        for (int i = 2; i <= n; i++) {
            int temp = first + second;
            second = first;
            first = temp;
        }
        return first;
    }
}