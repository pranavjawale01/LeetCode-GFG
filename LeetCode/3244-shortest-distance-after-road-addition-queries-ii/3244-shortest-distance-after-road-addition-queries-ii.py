class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        ans = []
        curr = [i for i in range(n)]
        for q in queries:
            l = bisect.bisect(curr,q[0])
            r = bisect.bisect_left(curr,q[1])
            for i in reversed(range(l, r)):
                curr.pop(i)
            ans.append(len(curr)-1)
        return ans






# TLE
# from sortedcontainers import SortedSet

# class Solution:
#     def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
#         st = SortedSet(range(n))
#         ans = []
#         for x in queries:
#             a = st.bisect_left(x[0] + 1)
#             b = st.bisect_right(x[1] - 1)
#             st = SortedSet(st[:a] + st[b:])
#             ans.append(len(st) - 1)
#         return ans