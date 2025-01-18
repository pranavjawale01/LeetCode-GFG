class Solution:
    def minCost(self, arr: List[int], brr: List[int], k: int) -> int:
        if arr == brr:
            return 0
        n = len(arr)
        if n == 1:
            return abs(arr[0] - brr[0])
        ans2 = sum(abs(arr[i] - brr[i]) for i in range(n))
        arr.sort()
        brr.sort()
        ans1 = k + sum(abs(arr[i] - brr[i]) for i in range(n))
        return min(ans1, ans2)