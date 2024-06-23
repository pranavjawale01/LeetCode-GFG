class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        maxpq = []
        minpq = []
        i, j = 0, 0
        maxlen = 0
        n = len(nums)

        while j < n:
            heappush(maxpq, (-nums[j], j))
            heappush(minpq, (nums[j], j))

            while -maxpq[0][0] - minpq[0][0] > limit:
                i = min(maxpq[0][1], minpq[0][1]) + 1

                while maxpq and maxpq[0][1] < i:
                    heappop(maxpq)
                while minpq and minpq[0][1] < i:
                    heappop(minpq)
                
            maxlen = max(maxlen, j - i + 1)
            j += 1
        
        return maxlen