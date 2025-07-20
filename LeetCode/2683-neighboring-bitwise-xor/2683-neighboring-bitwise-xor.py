class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        xor = 0
        for x in derived:
            xor ^= x
        return xor == 0