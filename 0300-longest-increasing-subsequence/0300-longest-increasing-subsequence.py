class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        tails = [0 for _ in range(len(nums))]
        size = 0
        for x in nums:
            i , j = 0 , size
            while i != j:
                n = (i + j) // 2
                if tails[n] < x:
                    i = n + 1
                else:
                    j = n
            tails[i] = x
            if i == size:
                size += 1
        return size