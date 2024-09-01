class Solution:
    def solve(self, n: int) -> str:
        return f"{n:04d}"
    
    def generateKey(self, num1: int, num2: int, num3: int) -> int:
        s1 = self.solve(num1)
        s2 = self.solve(num2)
        s3 = self.solve(num3)
        ans = 0
        
        for i in range(4):
            ans = ans * 10 + min(int(s1[i]), int(s2[i]), int(s3[i]))
        
        return ans