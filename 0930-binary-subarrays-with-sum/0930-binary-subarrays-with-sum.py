class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        n = len(nums)
        mp = defaultdict(int)
        count = 0
        curr_sum = 0
        mp[0] = 1
        
        for num in nums:
            curr_sum += num
            if curr_sum - goal in mp:
                count += mp[curr_sum - goal]
            mp[curr_sum] += 1
        
        return count