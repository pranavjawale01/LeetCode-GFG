class Solution:
    def possibleToPlace(self, force: int, position: List[int], m: int) -> bool:
        prev = position[0]
        countBalls = 1
        for i in range(1, len(position)):
            curr = position[i]
            if (curr - prev >= force):
                countBalls += 1
                prev = curr
            if countBalls == m:
                break
        return countBalls == m

    def maxDistance(self, position: List[int], m: int) -> int:
        n = len(position)
        position.sort()
        minForce = 1
        maxForce = position[n-1] - position[0]
        result = 0
        while minForce <= maxForce:
            midForce = minForce + (maxForce - minForce) // 2
            if (self.possibleToPlace(midForce, position, m)):
                result = midForce
                minForce = midForce + 1
            else:
                maxForce = midForce - 1
        return result