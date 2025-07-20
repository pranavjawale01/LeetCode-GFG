class Solution:
    def minChanges(self, nums: List[int], k: int) -> int:
        freq = [0] * (k + 1)
        vec = []
        n = len(nums)

        for i in range(n // 2):
            diff = abs(nums[i] - nums[n-i-1])
            freq[diff] += 1
            a = nums[i]
            b = nums[n-i-1]
            threshold = max(max(a, b), k - min(a, b))
            vec.append(threshold)

        vec.sort()
        ans = n // 2
        n //= 2

        for i in range(k+1):
            rest = n - freq[i]
            greater = self.lower_bound(vec, i)
            ans = min(ans, rest+greater)
        
        return ans

    def lower_bound(self, vec, target):
        left = 0
        right = len(vec)
        while left < right:
            mid = (left + right) // 2
            if vec[mid] < target:
                left = mid + 1
            else:
                right = mid
        return left