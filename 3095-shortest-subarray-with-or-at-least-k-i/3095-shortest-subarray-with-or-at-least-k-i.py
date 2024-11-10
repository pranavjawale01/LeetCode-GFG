class Solution:
    def solve1(self, val, bitarr, isAdd):
        i = 0
        while val > 0:
            bitarr[i] += (1 if isAdd else -1) * (val % 2)
            val //= 2
            i += 1

    def solve2(self, k, bitarr):
        val = 0
        for i in range(32):
            if bitarr[i]:
                val |= (1 << i)
        return val >= k

    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        i = 0
        j = 0
        ans = float('inf')
        bitarr = [0] * 32

        while j < n:
            self.solve1(nums[j], bitarr, True)
            while i <= j and self.solve2(k, bitarr):
                ans = min(ans, j - i + 1)
                self.solve1(nums[i], bitarr, False)
                i += 1
            j += 1
            
        return -1 if ans == float('inf') else ans