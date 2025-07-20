class Solution:
    def countKConstraintSubstrings(self, s: str, k: int) -> int:
        zero = 0
        one = 0
        count = 0
        for i in range(len(s)):
            if ord(s[i]) - ord('0') == 0:
                zero += 1
            else:
                one += 1

            localZero = zero
            localOne = one
            for j in range(i+1):

                if min(localZero, localOne) <= k:
                    count += 1

                if ord(s[j]) - ord('0') == 0:
                    localZero -= 1
                else:
                    localOne -= 1
        return count