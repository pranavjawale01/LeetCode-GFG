class Solution:
    def slidingWindow(self, nums: List[int], k: int) -> int:
        mp = defaultdict(int)
        i, count, n = 0, 0, len(nums)
        for j in range(n):
            mp[nums[j]] += 1
            while len(mp) > k:
                mp[nums[i]] -= 1
                if mp[nums[i]] == 0:
                    del mp[nums[i]]
                i += 1
            count += j - i + 1
        return count

    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        return self.slidingWindow(nums, k) - self.slidingWindow(nums, k - 1)