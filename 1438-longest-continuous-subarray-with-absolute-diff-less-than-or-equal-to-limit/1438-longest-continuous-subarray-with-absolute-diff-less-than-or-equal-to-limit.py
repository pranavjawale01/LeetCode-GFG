from sortedcontainers import SortedList

class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        n = len(nums)
        st = SortedList()
        i = 0
        j = 0
        maxLength = 0

        while j < n:
            st.add(nums[j])

            while st[-1] - st[0] > limit:
                st.remove(nums[i])
                i += 1

            maxLength = max(maxLength, j - i + 1)
            j += 1

        return maxLength




# class Solution:
#     def longestSubarray(self, nums: List[int], limit: int) -> int:
#         maxpq = []
#         minpq = []
#         i, j = 0, 0
#         maxlen = 0
#         n = len(nums)

#         while j < n:
#             heappush(maxpq, (-nums[j], j))
#             heappush(minpq, (nums[j], j))

#             while -maxpq[0][0] - minpq[0][0] > limit:
#                 i = min(maxpq[0][1], minpq[0][1]) + 1

#                 while maxpq and maxpq[0][1] < i:
#                     heappop(maxpq)
#                 while minpq and minpq[0][1] < i:
#                     heappop(minpq)
                
#             maxlen = max(maxlen, j - i + 1)
#             j += 1
        
#         return maxlen