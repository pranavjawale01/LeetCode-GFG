class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        n = len(nums)
        mp = {}
        mp[0] = 1
        sum = 0
        result = 0
        for i in range(n):
            sum += nums[i]
            rem = sum % k
            if rem < 0:
                rem += k
            if rem in mp:
                result += mp[rem]
            mp[rem] = mp.get(rem, 0) + 1
        return result