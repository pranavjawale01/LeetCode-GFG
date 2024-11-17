class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        n = len(nums)
        prefixSum = [0] * (n + 1)
        for i in range(n):
            prefixSum[i+1] = prefixSum[i] + nums[i]

        dq = deque()
        ans = float('inf')
        for i in range(n+1):
            while dq and prefixSum[i] - prefixSum[dq[0]] >= k:
                ans = min(ans, i - dq[0])
                dq.popleft()
            while dq and prefixSum[i] <= prefixSum[dq[-1]]:
                dq.pop()
            dq.append(i)
        return ans if ans != float('inf') else -1