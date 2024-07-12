class Solution:
    def solve(self, s: str, targetStr: str, points: int) -> int:
        totalPoints = 0
        st = []
        for char in s:
            if st and char == targetStr[1] and st[-1] == targetStr[0]:
                st.pop()
                totalPoints += points
            else:
                st.append(char)
        
        s = ''.join(st)
        return totalPoints, s

    def maximumGain(self, s: str, x: int, y: int) -> int:
        s1, s2 = "ab", "ba"
        if y > x:
            x, y = y, x
            s1, s2 = s2, s1
        
        points1, s = self.solve(s, s1, x)
        points2, _ = self.solve(s, s2, y)
        
        return points1 + points2