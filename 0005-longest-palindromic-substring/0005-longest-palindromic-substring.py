class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) <= 1:
            return s
        n = len(s)
        st, end = 0, 0
        max_len = 1
        for i in range(n):
            l, r = i, i
            while l >= 0 and r < n and s[l] == s[r]:
                l, r = l - 1, r + 1
            length_ = r - l - 1
            if length_ > max_len:
                max_len = length_
                st, end = l + 1, r - 1

            l, r = i, i + 1
            while l >= 0 and r < n and s[l] == s[r]:
                l, r = l - 1, r + 1
            length_ = r - l - 1
            if length_ > max_len:
                max_len = length_
                st, end = l + 1, r - 1

        return s[st:end + 1]