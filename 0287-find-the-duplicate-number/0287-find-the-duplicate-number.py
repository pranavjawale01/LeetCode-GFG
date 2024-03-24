class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        mp = defaultdict(int)
        for num in nums:
            mp[num] += 1
            if mp[num] > 1:
                return num
        return -1