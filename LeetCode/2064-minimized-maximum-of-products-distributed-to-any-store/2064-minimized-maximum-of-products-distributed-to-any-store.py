class Solution:
    def possible(self, x: int, quantities: List[int], n: int) -> bool:
        for a in quantities:
            # Compute the ceiling of a / x
            n -= (a + x - 1) // x
            if n < 0:
                return False
        return True

    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        l, r = 1, max(quantities)
        ans = 0
        while l <= r:
            mid = l + (r - l) // 2
            if self.possible(mid, quantities, n):
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
        return ans