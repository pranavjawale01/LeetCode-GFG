class Solution:
    def solve(self, nums: List[int], k: int) -> int:
        count, ans, start, end = 0, 0, 0, 0
        n = len(nums)
        while end < n:
            if nums[end] % 2 == 1:
                count += 1
            while count > k:
                if nums[start] % 2 == 1:
                    count -= 1
                start += 1
            ans += end - start + 1
            end += 1
        return ans


    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        return self.solve(nums, k) - self.solve(nums, k-1)



# class Solution:
#     def numberOfSubarrays(self, nums: List[int], k: int) -> int:
#         mp = {}
#         odd, count, n = 0, 0, len(nums)
#         for i in range(n):
#             if nums[i] % 2 == 1:
#                 odd += 1
#             if odd == k:
#                 count += 1
#             if odd - k in mp:
#                 count += mp[odd - k]
#             if odd in mp:
#                 mp[odd] += 1
#             else:
#                 mp[odd] = 1
#         return count