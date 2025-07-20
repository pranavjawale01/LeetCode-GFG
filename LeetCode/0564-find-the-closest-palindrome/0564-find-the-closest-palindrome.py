class Solution:
    def solve(self, firstHalf, isEven):
        resultNum = firstHalf
        if not isEven:
            firstHalf //= 10
        while firstHalf > 0:
            digit = firstHalf % 10
            resultNum = resultNum * 10 + digit
            firstHalf //= 10
        return resultNum

    def nearestPalindromic(self, n: str) -> str:
        l = len(n)
        mid = l // 2
        firstHalfLen = mid if l % 2 == 0 else mid + 1
        firstHalf = int(n[:firstHalfLen])
        possibleResults = [
            self.solve(firstHalf, l % 2 == 0),
            self.solve(firstHalf + 1, l % 2 == 0),
            self.solve(firstHalf - 1, l % 2 == 0),
            10**(l - 1) - 1,
            10**l + 1
        ]

        diff = float('inf')
        result = -1
        originalNum = int(n)

        for num in possibleResults:
            if num == originalNum:
                continue
            if abs(num - originalNum) < diff:
                diff = abs(num - originalNum)
                result = num
            elif abs(num - originalNum) == diff:
                result = min(result, num)

        return str(result)





# class Solution:
#     def nearestPalindromic(self, n: str) -> str:
#         length = len(n)
#         prefix = int(n[:(length + 1) // 2])
#         candidates = set()
        
#         for i in range(-1, 2):
#             p = str(prefix + i)
#             pal = p + p[::-1][length % 2:]
#             candidates.add(int(pal))
        
#         candidates.add(10**(length - 1) - 1)
#         candidates.add(10**length + 1)
        
#         num = int(n)
#         min_diff = float('inf')
#         result = 0
        
#         for candidate in candidates:
#             if candidate != num:
#                 diff = abs(candidate - num)
#                 if diff < min_diff or (diff == min_diff and candidate < result):
#                     min_diff = diff
#                     result = candidate
        
#         return str(result)