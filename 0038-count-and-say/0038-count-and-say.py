class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        temp = self.countAndSay(n - 1)
        result, count = "", 1
        for i in range(len(temp)):
            if i + 1 < len(temp) and temp[i] == temp[i + 1]:
                count += 1
            else:
                result += str(count) + temp[i]
                count = 1
        return result