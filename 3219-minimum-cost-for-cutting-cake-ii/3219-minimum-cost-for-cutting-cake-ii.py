class Solution:
    def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
        horizontalCut.sort()
        verticalCut.sort()

        horizontalCut = horizontalCut[::-1]
        verticalCut   = verticalCut[::-1]
        
        h, v = 0, 0
        verticalPieces, horizontalPieces = 1, 1
        totalCost = 0
        
        while h < len(horizontalCut) and v < len(verticalCut):
            if horizontalCut[h] > verticalCut[v]:
                totalCost = totalCost + horizontalCut[h] * verticalPieces
                horizontalPieces += 1
                h += 1
            else:
                totalCost = totalCost + verticalCut[v] * horizontalPieces
                verticalPieces += 1
                v += 1
        
        while h < len(horizontalCut):
            totalCost = totalCost + horizontalCut[h] * verticalPieces
            h += 1
        
        while v < len(verticalCut):
            totalCost = totalCost + verticalCut[v] * horizontalPieces
            v += 1
        
        return totalCost