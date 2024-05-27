class Solution:
    def specialArray(self, nums: List[int]) -> int:
        n = len(nums)
        arr = [0] * (n+1)
        for i in range(n):
            arr[min(n, nums[i])] += 1
        cum_sum = 0
        for i in range(n, -1, -1):
            cum_sum += arr[i]
            if i == cum_sum:
                return i
        return -1


# class Solution:
#     def specialArray(self, nums: List[int]) -> int:
#         nums.sort()
#         n = len(nums)
#         l , r = 0, n
#         while l <= r:
#             mid_x = l + (r - l) // 2
#             idx = bisect_left(nums, mid_x)
#             count = n - idx
#             if count == mid_x:
#                 return mid_x
#             elif count > mid_x:
#                 l = mid_x + 1
#             else:
#                 r = mid_x - 1
#         return -1



# class Solution:
#     def specialArray(self, nums: List[int]) -> int:
#         nums.sort()
#         n = len(nums)
#         for x in range(n+1):
#             idx = bisect_left(nums, x)
#             count = n - idx
#             if count == x:
#                 return x
#         return -1