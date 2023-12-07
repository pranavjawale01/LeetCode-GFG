class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        count , index = [0 , 0, 0] , 0
        for num in nums:
            count[num] += 1
        for i in range(3):
            for j in range(count[i]):
                nums[index] = i
                index += 1