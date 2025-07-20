class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int a = 0, b = 0, c = 0;
        for (char ch : s) {
            if (ch == 'a') a++;
            if (ch == 'b') b++;
            if (ch == 'c') c++;
        }
        if (a < k || b < k || c < k) return -1;
        int i = 0, j = 0;
        int ans = 0;
        while (j < n) {
            if (s[j] == 'a') a--;
            if (s[j] == 'b') b--;
            if (s[j] == 'c') c--;
            while (i <= j && (a < k || b < k || c < k)) {
                if (s[i] == 'a') a++;
                if (s[i] == 'b') b++;
                if (s[i] == 'c') c++;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return n - ans;
    }
};