class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        n = len(nums)
        check = [0] * (n + 1)
        
        for x in queries:
            l = x[0]
            r = x[1]
            check[l] -= 1
            if r + 1 < n:
                check[r + 1] += 1
        
        temp = 0
        for i in range(n):
            temp += check[i]
            nums[i] += temp
            if nums[i] < 0:
                nums[i] = 0
        
        return all(x == 0 for x in nums)