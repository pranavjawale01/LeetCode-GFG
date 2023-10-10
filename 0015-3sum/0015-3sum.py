class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res: List[List[int]] = []
        nums.sort()
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            target = -nums[i]
            front = i + 1
            back = len(nums) - 1
            while front < back:
                summation = nums[front] + nums[back]
                if summation < target:
                    front += 1
                elif summation > target:
                    back -= 1
                else:
                    res.append([nums[i], nums[front], nums[back]])
                    while front < back and nums[front] == nums[front + 1]:
                        front += 1
                    while front < back and nums[back] == nums[back - 1]:
                        back -= 1
                    front += 1
                    back -= 1
        return res