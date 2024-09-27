class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        ans = 0
        curr_sum = 0
        freq_map = {}
        j = 0
        
        for i in range(len(nums)):
            curr_sum += nums[i]
            freq_map[nums[i]] = freq_map.get(nums[i], 0) + 1
            
            while freq_map[nums[i]] > 1:
                freq_map[nums[j]] -= 1
                curr_sum -= nums[j]
                j += 1
            
            if i - j + 1 == k:
                ans = max(ans, curr_sum)
                freq_map[nums[j]] -= 1
                curr_sum -= nums[j]
                j += 1
        
        return ans