class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        n = len(nums)
        swapped = True
        for i in range(n):
            swapped = False
            for j in range(n - i - 1):
                if nums[j] <= nums[j + 1]:
                    continue
                else:
                    if bin(nums[j]).count('1') == bin(nums[j + 1]).count('1'):
                        nums[j], nums[j + 1] = nums[j + 1], nums[j]
                        swapped = True
                    else:
                        return False
            if not swapped:
                break
        return True