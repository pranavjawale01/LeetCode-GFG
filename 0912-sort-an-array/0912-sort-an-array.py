class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        minE = min(nums)
        maxE = max(nums)

        mp = {}
        for num in nums:
            if num not in mp:
                mp[num] = 1
            else:
                mp[num] += 1

        j = 0
        for i in range(minE, maxE + 1):
            if i in mp:
                while mp[i] > 0:
                    nums[j] = i
                    j += 1
                    mp[i] -= 1
        
        return nums