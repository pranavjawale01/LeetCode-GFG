class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        mp = defaultdict(int)
        ans , maxCount = 0, 0
        for num in nums:
            mp[num] += 1
            maxCount = max(maxCount, mp[num])
        for num, count in mp.items():
            if count == maxCount:
                ans += count
        return ans