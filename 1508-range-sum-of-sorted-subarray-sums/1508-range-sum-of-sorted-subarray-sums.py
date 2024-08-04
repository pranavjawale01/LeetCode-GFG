class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        arr = []
        
        for i in range(n):
            sum = 0
            for j in range(i, n):
                sum += nums[j]
                arr.append(sum)
        
        arr.sort()
        
        MOD = 1_000_000_007
        ans = 0
        for i in range(left - 1, right):
            ans = (ans + arr[i]) % MOD
        
        return ans