class Solution:
    def __init__(self):
        self.K = 0
        self.ans = 0

    def solve(self, nums: List[int], i: int, mp: defaultdict(int)):
        if i == len(nums):
            self.ans += 1
            return

        self.solve(nums, i + 1, mp)
        
        if mp[nums[i] - self.K] == 0 and mp[nums[i] + self.K] == 0:
            mp[nums[i]] += 1
            self.solve(nums, i + 1, mp)
            mp[nums[i]] -= 1

    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        self.K = k
        mp = defaultdict(int)
        self.solve(nums, 0, mp)
        return self.ans - 1