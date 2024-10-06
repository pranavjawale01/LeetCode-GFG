class Solution:
    def intToBinary(self, n: int) -> str:
        if n == 0:
            return "0"
        ans = ""
        while n > 0:
            ans = ('0' if n % 2 == 0 else '1') + ans
            n //= 2
        return ans

    def maxGoodNumber(self, nums: List[int]) -> int:
        ans = [self.intToBinary(x) for x in nums]
        
        ans.sort(key=lambda a: a * 32, reverse=True)

        res = ''.join(ans)
        return int(res, 2)