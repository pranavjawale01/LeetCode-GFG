class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        n = len(nums)
        mp = Counter(nums)
        
        if len(mp) == n:
            return 0
        
        ans = 0
        while nums:
            for i in range(3):
                if nums:
                    first = nums.pop(0)
                    mp[first] -= 1
                    if mp[first] == 0:
                        del mp[first]
            ans += 1
            
            if len(mp) == len(nums):
                break
        
        return ans