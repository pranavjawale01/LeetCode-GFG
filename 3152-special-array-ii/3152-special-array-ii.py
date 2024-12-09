class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        n = len(nums)
        m = len(queries)

        idx = [0] * n
        i, j = 0, 0
        while i < n:
            if j < i:
                j = i
            while j + 1 < n and nums[j] % 2 != nums[j + 1] % 2:
                j += 1
            idx[i] = j
            i += 1

        ans = [False] * m
        for i in range(m):
            s, e = queries[i]
            if e <= idx[s]:
                ans[i] = True

        return ans








# class Solution:
#     def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
#         n = len(nums)
#         m = len(queries)

#         cumSum = [0] * n
#         for i in range(1, n):
#             if nums[i] % 2 == nums[i - 1] % 2:
#                 cumSum[i] = cumSum[i - 1] + 1
#             else:
#                 cumSum[i] = cumSum[i - 1]

#         result = [False] * m
#         i = 0
#         for query in queries:
#             start, end = query
#             if cumSum[end] - cumSum[start] == 0:
#                 result[i] = True
#             i += 1

#         return result