class Solution:
    def check(self, x: int, y: int) -> bool:
        s1 = str(x)
        s2 = str(y)
        n, m = len(s1), len(s2)
        maxlen = max(n, m)
        
        s1 = s1.zfill(maxlen)
        s2 = s2.zfill(maxlen)
        
        diff = 0
        mp1, mp2 = {}, {}
        
        for i in range(maxlen):
            if s1[i] != s2[i]:
                diff += 1
            mp1[s1[i]] = mp1.get(s1[i], 0) + 1
            mp2[s2[i]] = mp2.get(s2[i], 0) + 1
        
        return diff <= 2 and mp1 == mp2

    def countPairs(self, nums: List[int]) -> int:
        count = 0
        n = len(nums)
        
        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] == nums[j]:
                    count += 1
                elif self.check(nums[i], nums[j]):
                    count += 1
        
        return count