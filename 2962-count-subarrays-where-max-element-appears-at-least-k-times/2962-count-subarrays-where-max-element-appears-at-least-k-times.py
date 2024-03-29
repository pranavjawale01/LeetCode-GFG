class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        max_e = max(nums)
        n = len(nums)
        result = 0
        id = []
        
        for i in range(n):
            if nums[i] == max_e:
                id.append(i)
            size = len(id)
            if size >= k:
                last_i = id[size - k]
                result += last_i + 1
        return result
        
# class Solution:
#     def countSubarrays(self, nums: List[int], k: int) -> int:
#         maxE = max(nums)
#         i, j, n, countMax, result = 0, 0, len(nums), 0, 0
#         while j < n:
#             if nums[j] == maxE:
#                 countMax += 1
#             while countMax >= k:
#                 result += n - j
#                 if nums[i] == maxE:
#                     countMax -= 1
#                 i += 1
#             j += 1
#         return result