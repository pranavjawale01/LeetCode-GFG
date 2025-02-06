class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        n = len(nums)
        mp = {}
        for i in range(n):
            for j in range(i+1, n):
                if nums[i] * nums[j] in mp:
                    mp[nums[i] * nums[j]] += 1
                else:
                    mp[nums[i] * nums[j]] = 1
        ans = 0
        for count in mp.values():
            ans += (count * (count - 1)) // 2

        return ans * 8





# class Solution:
#     def tupleSameProduct(self, nums: List[int]) -> int:
#         nums.sort()
#         n = len(nums)
#         count = 0

#         for i in range(n):
#             for j in range(n - 1, i, -1):
#                 val = nums[i] * nums[j]
#                 st = set()
#                 for k in range(i + 1, j):
#                     if val % nums[k] == 0:
#                         data = val // nums[k]
#                         if data in st:
#                             count += 1
#                         st.add(nums[k])

#         return count * 8