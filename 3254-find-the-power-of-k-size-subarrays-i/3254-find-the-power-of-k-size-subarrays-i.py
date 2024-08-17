class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        ans = [-1] * (n-k+1)
        for i in range(0, n-k+1):
            flag = True
            for j in range(i, i+k-1):
                if nums[j] != nums[j+1] - 1:
                    flag = False
                    break
            if flag:
                ans[i] = nums[i+k-1]
        return ans