class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        ans = []
        mp = defaultdict(int)
        for num in nums:
            mp[num] += 1
            if mp[num] > 1:
                ans.append(num)
        return ans