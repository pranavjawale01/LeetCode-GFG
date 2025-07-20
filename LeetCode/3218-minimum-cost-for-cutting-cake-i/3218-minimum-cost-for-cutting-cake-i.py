class Solution:
    def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
        horizontalCut.sort()
        verticalCut.sort()
        
        horizontalCut = horizontalCut[::-1]
        verticalCut   = verticalCut[::-1]

        h, v = 0, 0
        horizontalPieces, verticalPieces = 1, 1
        totalCost = 0
        MOD = 1000000007
        
        while h < len(horizontalCut) and v < len(verticalCut):
            if horizontalCut[h] > verticalCut[v]:
                totalCost = (totalCost + horizontalCut[h] * verticalPieces) % MOD
                horizontalPieces += 1
                h += 1
            else:
                totalCost = (totalCost + verticalCut[v] * horizontalPieces) % MOD
                verticalPieces += 1
                v += 1
        
        while h < len(horizontalCut):
            totalCost = (totalCost + horizontalCut[h] * verticalPieces) % MOD
            h += 1
        
        while v < len(verticalCut):
            totalCost = (totalCost + verticalCut[v] * horizontalPieces) % MOD
            v += 1
        
        return totalCost