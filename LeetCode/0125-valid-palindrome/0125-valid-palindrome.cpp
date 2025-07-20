class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
        
        for (char c : s) {
            if (isalnum(c)) {
                ans += tolower(c);
            }
        }
        
        int n = ans.length();
        int i = 0, j = n - 1;
        
        while (i < j) {
            if (ans[i] != ans[j]) {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
};