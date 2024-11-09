class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        maxVal = max(nums)
        n = maxVal + k + 2
        freq = [0] * n
        for x in nums:
            freq[x] += 1
        freqPref = [0] * n
        freqPref[0] = freq[0]
        for i in range(1, n):
            freqPref[i] = freqPref[i - 1] + freq[i]
        ans = 0
        for i in range(n):
            if freq[i] == 0 and numOperations == 0:
                continue
            l = max(0, i - k)
            r = min(n - 1, i + k)
            total = freqPref[r] - (freqPref[l - 1] if l > 0 else 0)
            temp = total - freq[i]
            res = freq[i] + min(numOperations, temp)
            ans = max(ans, res)
        return ans