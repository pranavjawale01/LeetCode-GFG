class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        n,c1,c2 = len(colors),0,0
        if n < 3:
            return False
        for i in range(1,n-1):
            if colors[i] == colors[i-1] and colors[i] == colors[i+1]:
                if colors[i] == 'A':
                    c1 += 1
                if colors[i] == 'B':
                    c2 += 1
        return c1 > c2