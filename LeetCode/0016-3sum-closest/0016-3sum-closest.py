class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        finalSum = nums[0] + nums[1] + nums[2]
        for i in range(len(nums)-2):
            front , back = i+1, len(nums)-1
            while front < back:
                temp = nums[i] + nums[front] + nums[back]
                if abs(temp-target) < abs(finalSum-target):
                    finalSum = temp
                if temp > target:
                    back -= 1
                elif temp < target:
                    front += 1
                else:
                    return finalSum
        return finalSum