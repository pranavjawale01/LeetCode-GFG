class Solution:
    def merge(self, nums: List[int], low: int, mid: int, high: int) -> None:
        temp = []
        left, right = low, mid + 1
        
        while left <= mid and right <= high:
            if nums[left] <= nums[right]:
                temp.append(nums[left])
                left += 1
            else:
                temp.append(nums[right])
                right += 1
        
        while left <= mid:
            temp.append(nums[left])
            left += 1
        
        while right <= high:
            temp.append(nums[right])
            right += 1
        
        nums[low:high + 1] = temp

    def countPairs(self, nums: List[int], low: int, mid: int, high: int) -> int:
        count = 0
        right = mid + 1
        
        for i in range(low, mid + 1):
            while right <= high and nums[i] > 2 * nums[right]:
                right += 1
            count += right - (mid + 1)
        
        return count

    def mergeSort(self, nums: List[int], low: int, high: int) -> int:
        if low >= high:
            return 0
        
        mid = (low + high) // 2
        count = 0
        
        count += self.mergeSort(nums, low, mid)
        count += self.mergeSort(nums, mid + 1, high)
        count += self.countPairs(nums, low, mid, high)
        self.merge(nums, low, mid, high)
        
        return count

    def reversePairs(self, nums: List[int]) -> int:
        return self.mergeSort(nums, 0, len(nums) - 1)