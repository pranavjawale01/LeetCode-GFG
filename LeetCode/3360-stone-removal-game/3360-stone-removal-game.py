class Solution:
    def canAliceWin(self, n: int) -> bool:
        stone = 10
        while n >= 0:
            if n >= stone:
                n -= stone
                stone -= 1
            else:
                return False
            if n >= stone:
                n -= stone
                stone -= 1
            else:
                return True
        return True