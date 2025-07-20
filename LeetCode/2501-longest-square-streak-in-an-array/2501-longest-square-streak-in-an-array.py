class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        st = set(nums)
        ans = 0
        
        for x in nums:
            count = 0
            current = x
            while current in st:
                count += 1
                current *= current
                if current > 1e5:
                    break
            if count >= 2:
                ans = max(ans, count)
        
        return -1 if ans == 0 else ans