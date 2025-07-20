class Solution:
    def customBinarySearch(self, items: List[List[int]], queryPrice: int) -> int:
        l, r = 0, len(items) - 1
        maxBeauty = 0
        while l <= r:
            mid = l + (r - l) // 2
            if items[mid][0] > queryPrice:
                r = mid - 1
            else:
                maxBeauty = max(maxBeauty, items[mid][1])
                l = mid + 1
        return maxBeauty

    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        items.sort()
        n, m = len(items), len(queries)
        ans = [0] * m
        maxBeautySeen = items[0][1]
        for i in range(1, n):
            maxBeautySeen = max(maxBeautySeen, items[i][1])
            items[i][1] = maxBeautySeen
        for i in range(m):
            ans[i] = self.customBinarySearch(items, queries[i])
        return ans