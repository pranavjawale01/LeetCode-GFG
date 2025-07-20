class Solution:
    def myAtoi(self, s: str) -> int:
        slen = len(s)
        if slen == 0:
            return 0
        i, sign, result = 0, 1, 0
        while i < slen and s[i] == ' ':
            i += 1
        if i < slen and (s[i] == '-' or s[i] == '+'):
            sign = -1 if s[i] == '-' else 1
            i += 1
        while i < slen and s[i].isdigit():
            digit = int(s[i])
            if result > (2**31 - 1) // 10 or (result == (2**31 - 1) // 10 and digit > 7):
                return (2**31 - 1) if sign == 1 else (-2**31)
            result = result * 10 + digit
            i += 1
        return result * sign