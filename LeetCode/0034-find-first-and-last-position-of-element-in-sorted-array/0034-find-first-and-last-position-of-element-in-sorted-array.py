class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        result = []
        low, high = 0, len(nums) - 1
        while low <= high:
            mid = low + (high - low) // 2
            if nums[mid] == target:
                start, end = mid, mid
                while start > 0 and nums[start - 1] == target:
                    start -= 1
                while end < len(nums) - 1 and nums[end + 1] == target:
                    end += 1
                result.append(start)
                result.append(end)
                return result
            elif nums[mid] < target:
                low = mid + 1
            else:
                high = mid - 1
        result.append(-1)
        result.append(-1)
        return result