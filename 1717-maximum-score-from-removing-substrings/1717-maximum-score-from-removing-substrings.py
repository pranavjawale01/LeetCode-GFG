class Solution:
    def solve(self, s: str, targetStr: str, points: int) -> tuple[int, str]:
        totalPoints = 0
        n = len(s)
        write_idx = 0
        s = list(s)
        for read_idx in range(n):
            s[write_idx] = s[read_idx]
            write_idx += 1
            if write_idx > 1 and s[write_idx - 1] == targetStr[1] and s[write_idx - 2] == targetStr[0]:
                write_idx -= 2
                totalPoints += points
        
        s = ''.join(s[:write_idx])
        return totalPoints, s

    def maximumGain(self, s: str, x: int, y: int) -> int:
        s1, s2 = "ab", "ba"
        if y > x:
            s1, s2 = s2, s1
            x, y = y, x

        points1, s = self.solve(s, s1, x)
        points2, _ = self.solve(s, s2, y)

        return points1 + points2





# class Solution:
#     def solve(self, s: str, targetStr: str, points: int) -> int:
#         totalPoints = 0
#         st = []
#         for char in s:
#             if st and char == targetStr[1] and st[-1] == targetStr[0]:
#                 st.pop()
#                 totalPoints += points
#             else:
#                 st.append(char)
        
#         s = ''.join(st)
#         return totalPoints, s

#     def maximumGain(self, s: str, x: int, y: int) -> int:
#         s1, s2 = "ab", "ba"
#         if y > x:
#             x, y = y, x
#             s1, s2 = s2, s1
        
#         points1, s = self.solve(s, s1, x)
#         points2, _ = self.solve(s, s2, y)
        
#         return points1 + points2