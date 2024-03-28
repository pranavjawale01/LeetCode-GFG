class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        mp = defaultdict(int)
        i, j , long_len , n = 0, 0, 0, len(nums)
        while j < n:
            mp[nums[j]] += 1
            while i < j and mp[nums[j]] > k:
                nums[i] -= 1
                i += 1
            long_len = max(long_len, j - i + 1)
            j += 1

        return long_len