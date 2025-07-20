class Solution:
    def solve(self, mp, x):
        pq = []
        
        for key, value in mp.items():
            heapq.heappush(pq, (value, key))
            if len(pq) > x:
                heapq.heappop(pq)

        sum_result = 0
        while pq:
            value, key = heapq.heappop(pq)
            sum_result += key * value
            
        return sum_result

    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        n = len(nums)
        mp = defaultdict(int)

        for i in range(k):
            mp[nums[i]] += 1
            
        ans = [0] * (n - k + 1)
        ans[0] = self.solve(mp, x)
        
        for i in range(k, n):
            outgoing = nums[i - k]
            mp[outgoing] -= 1
            if mp[outgoing] == 0:
                del mp[outgoing]
                
            incoming = nums[i]
            mp[incoming] += 1
            ans[i - k + 1] = self.solve(mp, x)
        
        return ans