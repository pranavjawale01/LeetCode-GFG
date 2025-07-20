class Solution:
    def largestOddNumber(self, num: str) -> str:
        result = ""
        for i in range(len(num) - 1, -1, -1):
            if int(num[i]) % 2 == 1:
                result = num[0: i+1]
                break
        return result