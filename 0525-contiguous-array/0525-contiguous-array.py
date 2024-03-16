class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        mp = defaultdict(int)
        mp[0] = -1
        result, currSum, n = 0, 0, len(nums)
        for i in range(n):
            currSum += 1 if nums[i] == 1 else -1
            if currSum in mp:
                result = max(result, i - mp[currSum])
            else:
                mp[currSum] = i
        return result