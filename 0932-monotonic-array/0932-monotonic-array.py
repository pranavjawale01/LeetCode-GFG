class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        order=0
        for i in range(1,len(nums)):
            if nums[i] > nums[i-1]:
                if(order==0):
                    order=1
                elif(order==-1):
                    return False
            elif nums[i] < nums[i-1]:
                if(order==0):
                    order=-1
                elif(order==1):
                    return False
        return True