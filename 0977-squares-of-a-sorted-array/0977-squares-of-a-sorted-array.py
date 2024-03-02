class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        i , j , k = 0, n-1, n-1
        arr = [0] * n
        while k >= 0:
            a = nums[i] * nums[i]
            b = nums[j] * nums[j]
            if a > b:
                arr[k] = a
                i += 1
            else:
                arr[k] = b
                j -= 1
            k -= 1
        return arr

# class Solution:
#     def sortedSquares(self, nums: List[int]) -> List[int]:
#         n = len(nums)
#         for i in range(n):
#             nums[i] = nums[i]*nums[i]
#         nums.sort()
#         return nums