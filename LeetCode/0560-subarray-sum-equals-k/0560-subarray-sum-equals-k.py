class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mp = defaultdict(int)
        mp[0] = 1
        result , cum_sum = 0, 0 

        for num in nums:
            cum_sum += num
            if cum_sum - k in mp:
                result += mp[cum_sum - k]
            mp[cum_sum] += 1
        
        return result