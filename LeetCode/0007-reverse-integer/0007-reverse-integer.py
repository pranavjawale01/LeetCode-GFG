class Solution:
    def reverse(self, x: int) -> int:
        max_int = pow(2,31)-1
        min_int = pow(-2,31)
        string = str(abs(x))
        reverse = string[::-1]
        result = int(reverse)
        if(result > max_int or result < min_int):
            return 0
        else:
            if x<0:
                return result*(-1)
            return result