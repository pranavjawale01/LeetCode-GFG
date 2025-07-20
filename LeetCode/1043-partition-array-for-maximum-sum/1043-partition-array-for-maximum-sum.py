class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        mem = [-1] * 501
        n = len(arr)

        def solve(i: int, arr: List[int], k: int) -> int:
            if (i >= n):
                return 0
            if mem[i] != -1:
                return mem[i]
            cur_max = -1
            result = 0
            for j in range(i, min(n, i + k)):
                cur_max = max(cur_max, arr[j])
                result = max(result, cur_max * (j - i + 1) + solve(j + 1, arr, k))

            mem[i] = result
            return result

        return solve(0, arr, k)