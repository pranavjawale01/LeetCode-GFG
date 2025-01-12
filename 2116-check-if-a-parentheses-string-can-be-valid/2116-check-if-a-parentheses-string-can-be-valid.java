class Solution {
    public boolean canBeValid(String s, String locked) {
        int n = s.length();
        if (n % 2 != 0) return false;

        int open = 0, free = 0;
        for (int i = 0; i < n; i++) {
            if (locked.charAt(i) == '0') {
                free++;
            } else if (s.charAt(i) == '(') {
                open++;
            } else {
                if (open > 0) {
                    open--;
                } else if (free > 0) {
                    free--;
                } else {
                    return false;
                }
            }
        }

        int close = 0;
        free = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (locked.charAt(i) == '0') {
                free++;
            } else if (s.charAt(i) == ')') {
                close++;
            } else {
                if (close > 0) {
                    close--;
                } else if (free > 0) {
                    free--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
}