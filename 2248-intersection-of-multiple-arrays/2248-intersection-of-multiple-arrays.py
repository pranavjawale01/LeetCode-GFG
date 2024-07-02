class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        mp = {}
        n = len(nums)
        for num in nums:
            for x in num:
                if x not in mp:
                    mp[x] = 1
                else:
                    mp[x] += 1
        ans = []
        for key, val in mp.items():
            if val == n:
                ans.append(key)
        ans.sort()
        return ans