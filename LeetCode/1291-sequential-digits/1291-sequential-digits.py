class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        digits = "123456789"
        output = []
        nl = len(str(low))
        nh = len(str(high))

        for i in range(nl, nh+1):
            for j in range(0, 10 - i):
                num = int(digits[j : j + i])
                if num >= low and num <= high:
                    output.append(num)
        
        return output