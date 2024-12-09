class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        
        for i in range(n):
            if nums[i] > 0:
                ans[i] = nums[(i + abs(nums[i])) % n]
            elif nums[i] < 0:
                j = i
                t = abs(nums[i])
                while t > 0:
                    j = (j - 1 + n) % n
                    t -= 1
                ans[i] = nums[j]
            else:
                ans[i] = nums[i]
        
        return ans