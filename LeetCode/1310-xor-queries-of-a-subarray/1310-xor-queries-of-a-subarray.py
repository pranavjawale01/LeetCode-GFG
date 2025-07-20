class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        n = len(arr)
        for i in range(1, n):
            arr[i] ^= arr[i-1]
        m = len(queries)
        ans = [0] * m
        for i in range(m):
            l, r = queries[i][0], queries[i][1]
            ans[i] = arr[r] ^ (0 if l == 0 else arr[l-1])
        return ans