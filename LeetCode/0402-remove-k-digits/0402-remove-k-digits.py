class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        n = len(num)
        if n == k:
            return "0"
        result = []
        for digit in num:
            while result and result[-1] > digit and k > 0:
                result.pop()
                k -= 1
            if result or digit != '0':
                result.append(digit)
        while result and k > 0:
            result.pop()
            k -= 1
        if not result:
            return "0"
        return ''.join(result)