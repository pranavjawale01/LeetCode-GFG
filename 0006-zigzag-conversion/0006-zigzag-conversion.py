class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s

        len_ = len(s)
        result = [""] * numRows
        cycleLen = 2 * numRows - 2

        for i in range(numRows):
            for j in range(i, len_, cycleLen):
                result[i] += s[j]
                if i != 0 and i != numRows - 1 and j + cycleLen - 2 * i < len_:
                    result[i] += s[j + cycleLen - 2 * i]

        return "".join(result)