class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        mp = {}
        odd, count, n = 0, 0, len(nums)
        for i in range(n):
            if nums[i] % 2 == 1:
                odd += 1
            if odd == k:
                count += 1
            if odd - k in mp:
                count += mp[odd - k]
            if odd in mp:
                mp[odd] += 1
            else:
                mp[odd] = 1
        return count