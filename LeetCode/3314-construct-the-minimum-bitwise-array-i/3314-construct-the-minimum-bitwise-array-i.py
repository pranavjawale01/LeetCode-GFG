class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        arr = [-1] * n
        for i in range(n):
            x = nums[i]
            for j in range(0, x+1):
                if (j | (j + 1)) == x:
                    arr[i] = j
                    break
        return arr