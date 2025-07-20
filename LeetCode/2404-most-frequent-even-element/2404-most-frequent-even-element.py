class Solution:
    def mostFrequentEven(self, nums: List[int]) -> int:
        mp = {}
        for x in nums:
            if x % 2 == 0:
                if x not in mp:
                    mp[x] = 1
                else:
                    mp[x] += 1
        
        ans = -1
        count = 0
        for k, v in mp.items():
            if v > count or (v == count and k < ans):
                count = v
                ans = k
        
        return ans