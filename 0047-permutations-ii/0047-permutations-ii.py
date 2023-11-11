class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        if not nums:
            return res

        nums.sort()
        used = [False] * len(nums)
        list_ = []

        self.dfs(nums, used, list_, res)
        return res

    def dfs(self, nums, used, list_, res):
        if len(list_) == len(nums):
            res.append(list_[:])
            return

        for i in range(len(nums)):
            if used[i]:
                continue
            if i > 0 and nums[i - 1] == nums[i] and not used[i - 1]:
                continue

            used[i] = True
            list_.append(nums[i])
            self.dfs(nums, used, list_, res)
            used[i] = False
            list_.pop()