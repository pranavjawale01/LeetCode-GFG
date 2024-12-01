class Solution:
    def getLargestOutlier(self, nums: List[int]) -> int:
        totalSum = 0
        mp = {}
        for x in nums:
            totalSum += x
            mp[x] = mp.get(x, 0) + 1
        
        ans = float('-inf')
        for x in nums:
            mp[x] -= 1
            if mp[x] == 0:
                del mp[x]
            rem = totalSum - x
            if rem % 2 == 0 and rem // 2 in mp:
                ans = max(ans, x)
            mp[x] = mp.get(x, 0) + 1
        
        return ans