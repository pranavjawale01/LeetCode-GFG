class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        maxE = max(nums)
        i, j, n, countMax, result = 0, 0, len(nums), 0, 0
        while j < n:
            if nums[j] == maxE:
                countMax += 1
            while countMax >= k:
                result += n - j
                if nums[i] == maxE:
                    countMax -= 1
                i += 1
            j += 1
        return result