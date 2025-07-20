class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low , high = 0 , len(nums)-1
        while(low<=high):
            mid = low + (high-low ) // 2
            if nums[mid] == target :
                return mid
            if nums[low]<=nums[mid] :
                if nums[low]<=target and target<nums[mid] :
                    high = mid - 1
                else:
                    low = mid + 1
            else:
                if nums[mid]<target and target<=nums[high] :
                    low = mid + 1
                else:
                    high = mid -1
        return -1