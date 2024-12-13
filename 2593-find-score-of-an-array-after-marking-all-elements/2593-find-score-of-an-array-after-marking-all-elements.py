class Solution:
    def findScore(self, nums: List[int]) -> int:
        ans = 0
        pq = [(nums[i], i) for i in range(len(nums))]
        heapq.heapify(pq)
        n = len(nums)
        vis = [False] * n
        while pq:
            val, idx = heapq.heappop(pq)
            if vis[idx]:
                continue
            ans += val
            vis[idx] = True
            if idx - 1 >= 0:
                vis[idx - 1] = True
            if idx + 1 < n:
                vis[idx + 1] = True
        return ans