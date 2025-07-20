class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        ans = 0
        minPosition = -1
        maxPosition = -1
        leftBound = -1

        for i in range(len(nums)):
            if nums[i] < minK or nums[i] > maxK:
                leftBound = i

            if nums[i] == minK:
                minPosition = i
            if nums[i] == maxK:
                maxPosition = i

            count = min(maxPosition, minPosition) - leftBound

            ans += 0 if count <= 0 else count

        return ans