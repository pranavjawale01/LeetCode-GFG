class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        n = len(s)
        result = "0" * n
        i = 0
        for ch in s:
            if ch == '1':
                if result[n - 1] == '1':
                    result = result[:i] + '1' + result[i+1:]
                    i += 1
                else:
                    result = result[:n-1] + '1'
        return result