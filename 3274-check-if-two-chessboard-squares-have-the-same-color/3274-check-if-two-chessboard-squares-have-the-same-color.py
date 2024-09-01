class Solution:
    def solve(self, s: str) -> str:
        row = int(s[1])
        col = ord(s[0]) - ord('a')
        if row % 2 == 1:
            if col % 2 == 1:
                return 'w'
            else:
                return 'b'
        else:
            if col % 2 == 1:
                return 'b'
            else:
                return 'w'
    
    def checkTwoChessboards(self, coordinate1: str, coordinate2: str) -> bool:
        color1 = self.solve(coordinate1)
        color2 = self.solve(coordinate2)
        return color1 == color2