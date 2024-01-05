class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        size = 0
        for x in nums:
            i , j = 0 , size
            while i != j:
                n = (i + j) // 2
                if nums[n] < x:
                    i = n + 1
                else:
                    j = n
            nums[i] = x
            if i == size:
                size += 1
        return size