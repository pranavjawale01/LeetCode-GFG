class Solution {
    public int takeCharacters(String s, int k) {
        int n = s.length();
        int a = 0, b = 0, c = 0;

        for (char ch : s.toCharArray()) {
            if (ch == 'a') a++;
            if (ch == 'b') b++;
            if (ch == 'c') c++;
        }

        if (a < k || b < k || c < k) return -1;

        int i = 0, j = 0;
        int ans = 0;

        while (j < n) {
            if (s.charAt(j) == 'a') a--;
            if (s.charAt(j) == 'b') b--;
            if (s.charAt(j) == 'c') c--;

            while (i <= j && (a < k || b < k || c < k)) {
                if (s.charAt(i) == 'a') a++;
                if (s.charAt(i) == 'b') b++;
                if (s.charAt(i) == 'c') c++;
                i++;
            }

            ans = Math.max(ans, j - i + 1);
            j++;
        }

        return n - ans;
    }
}