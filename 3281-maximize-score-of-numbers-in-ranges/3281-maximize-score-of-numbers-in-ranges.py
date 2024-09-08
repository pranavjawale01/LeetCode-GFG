class Solution:
    def maxPossibleScore(self, start: List[int], d: int) -> int:
        start.sort()
        n = len(start)
        low, high = 0, start[n - 1] + d - start[0]
        ans = 0

        def pranavjawale01(mid: int) -> bool:
            ans = start[0]
            for i in range(1, n):
                if mid + ans <= start[i] + d:
                    ans = max(ans + mid, start[i])
                else:
                    return False
            return True

        while low <= high:
            mid = low + (high - low) // 2
            if pranavjawale01(mid):
                ans = mid
                low = mid + 1
            else:
                high = mid - 1

        return ans