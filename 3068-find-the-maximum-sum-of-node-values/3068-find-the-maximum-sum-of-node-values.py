class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        normal_sum = 0
        fayda = [0] * len(nums)

        for i in range(len(nums)):
            fayda[i] = (nums[i] ^ k) - nums[i]
            normal_sum += nums[i]

        fayda.sort(reverse=True)

        for i in range(0, len(fayda) - 1, 2):
            pair_sum = fayda[i] + fayda[i + 1]
            if pair_sum > 0:
                normal_sum += pair_sum

        return normal_sum


# class Solution:
#     def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
#         sum_ = 0
#         count = 0
#         min_loss = float('inf')
        
#         for num in nums:
#             if (num ^ k) > num:
#                 count += 1
#                 sum_ += (num ^ k)
#             else:
#                 sum_ += num
#             min_loss = min(min_loss, abs(num - (num ^ k)))
        
#         if count % 2 == 0:
#             return sum_
#         return sum_ - min_loss