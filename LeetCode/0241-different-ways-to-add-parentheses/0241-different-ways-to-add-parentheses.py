class Solution:
    def solve(self, s: str) -> list[int]:
        arr = []
        
        for i in range(len(s)):
            if s[i] in ['+', '-', '*']:
                left = self.solve(s[:i])
                right = self.solve(s[i+1:])
                
                for x in left:
                    for y in right:
                        if s[i] == '+':
                            arr.append(x + y)
                        elif s[i] == '-':
                            arr.append(x - y)
                        else:
                            arr.append(x * y)
        
        if not arr:
            arr.append(int(s))
        
        return arr

    def diffWaysToCompute(self, expression: str) -> list[int]:
        return self.solve(expression)