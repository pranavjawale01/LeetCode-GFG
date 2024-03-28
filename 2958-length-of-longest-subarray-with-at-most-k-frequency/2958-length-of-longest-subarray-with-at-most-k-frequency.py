class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        mp = defaultdict(int)
        i, j , long_len , n = 0, 0, 0, len(nums)
        culprit = 0
        while j < n:
            mp[nums[j]] += 1
            if mp[nums[j]] == 1 + k:
                culprit += 1
            if culprit > 0:
                mp[nums[i]] -= 1
                if mp[nums[i]] == k:
                    culprit -= 1
                i += 1
            if culprit == 0:
                long_len = max(long_len, j - i + 1)
            j += 1
        return long_len

# class Solution:
#     def maxSubarrayLength(self, nums: List[int], k: int) -> int:
#         mp = defaultdict(int)
#         i, j , long_len , n = 0, 0, 0, len(nums)
#         while j < n:
#             mp[nums[j]] += 1
#             while i < j and mp[nums[j]] > k:
#                 mp[nums[i]] -= 1
#                 i += 1
#             long_len = max(long_len, j - i + 1)
#             j += 1

#         return long_len