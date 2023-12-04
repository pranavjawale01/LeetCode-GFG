class Solution:
    def largestGoodInteger(self, num: str) -> str:
        res = ""
        for i in range(len(num) - 2):
            temp = num[i:i+3]
            if temp[0] == temp[1] and temp[1] == temp[2]:
                if temp > res:
                    res = temp
        return res