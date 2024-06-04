class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_set<char> st;
        int result = 0;
        for (char c : s) {
            if (st.count(c)) {
                result += 2;
                st.erase(c);
            } else {
                st.insert(c);
            }
        }
        if (!st.empty()) {
            result++;
        }
        return result;
    }
};