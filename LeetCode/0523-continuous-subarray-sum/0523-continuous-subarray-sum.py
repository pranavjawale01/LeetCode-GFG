class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        sum_ = 0
        mp = {0: -1}
        
        for i in range(n):
            sum_ += nums[i]
            remainder = sum_ % k

            if remainder in mp:
                if i - mp[remainder] >= 2:
                    return True
            else:
                mp[remainder] = i

        return False