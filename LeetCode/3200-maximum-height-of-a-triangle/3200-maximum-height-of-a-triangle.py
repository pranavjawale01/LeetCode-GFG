class Solution:
    def solve(self, red: int, blue: int) -> int:
        height = 0
        row = 1
        while True:
            if row % 2 == 1:
                if red >= row:
                    red -= row
                    height += 1
                else:
                    break
            else:
                if blue >= row:
                    blue -= row
                    height += 1
                else:
                    break
            row += 1
        return height


    def maxHeightOfTriangle(self, red: int, blue: int) -> int:
        return max(self.solve(red, blue), self.solve(blue, red))