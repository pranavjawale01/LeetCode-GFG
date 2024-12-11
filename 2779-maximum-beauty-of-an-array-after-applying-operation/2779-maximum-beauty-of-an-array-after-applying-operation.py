class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        nums.sort()
        max_beauty = 0
        for i in range(len(nums)):
            upper_bound = bisect_right(nums, nums[i] + 2 * k)
            max_beauty = max(max_beauty, upper_bound - i)
        return max_beauty






# class Solution:
#     def maximumBeauty(self, nums: List[int], k: int) -> int:
#         ranges = []
#         for x in nums:
#             ranges.append((x - k, x + k))
#         ranges.sort()

#         max_beauty = 0
#         dq = deque()

#         for start, end in ranges:
#             while dq and dq[0] < start:
#                 dq.popleft()
#             dq.append(end)
#             max_beauty = max(max_beauty, len(dq))

#         return max_beauty